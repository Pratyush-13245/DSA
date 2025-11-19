
#include <iostream>
#include <vector>
#define LL long long
using namespace std;

class TopDown {
    // O(LIMIT*N) & O(1*N)
    LL solveWithoutMemo(LL n) {
        if(n == 1)
            return 1;

        LL sum = n + solveWithoutMemo(n - 1);

        return sum; 
    }
    
    // O(LIMIT*2) & O(1)
    LL solveWithMemo(vector<LL>& dp, LL n) {
        if(n == 1)
            return 1;

        // Memoization table: If result is already computed then return it
        if(dp[n] != -1) 
            return dp[n];
        
        LL sum = n + solveWithMemo(dp, n - 1);

        return dp[n] = sum; // Store sum to memoization table and then return it
    }

public:
    vector<LL> findSumFirstNaturalNums(LL LIMIT) {
        vector<LL> dp(LIMIT + 1, -1);
        vector<LL> answer;

        for(LL n = 1; n <= LIMIT; ++n) { 
            LL sum = solveWithMemo(dp, n);
            answer.push_back(sum);
        }

        return answer;
    }
};

class BottomUp {
    // O(2*LIMIT) & O(1*LIMIT)
    vector<LL> solveBy1DTable(LL LIMIT) {
        vector<LL> dp(LIMIT + 1, -1);
        dp[1] = 1; // Init base case

        vector<LL> answer;
        answer.push_back(1);

        for(LL n = 2; n <= LIMIT; ++n) { // In recursion we are moving from n to base case, in Bottom-up just move the reverse way, move from base case to n
            LL sum = n + dp[n - 1];
            dp[n]  = sum;
            answer.push_back(dp[n]);
        }

        return answer;
    }
    // Note: For calculating the result of any n we are dependent on the previous value, which is constant, so we could simply maintain one variable instead of using the dp array  

    // O(2*LIMIT) & O(1)
    vector<LL> solveWithoutTable(LL LIMIT) {
        int dp_n_1 = 1; // dp[n - 1]
        int dp_n   = 1; // dp[n]

        vector<LL> answer;
        answer.push_back(1);

        for(LL n = 2; n <= LIMIT; ++n) {
            LL sum = n + dp_n_1;
            dp_n   = sum;
            answer.push_back(dp_n);
            dp_n_1 = dp_n; // For any future n, the previous result has to be in dp_n_1 thus update it
        }

        return answer;
    }

public:
    vector<LL> findSumFirstNaturalNums(LL LIMIT) {
        return solveWithoutTable(LIMIT);
    }
};

// Driver code
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);

    LL LIMIT = 10;

    BottomUp bottomUp;
    vector<LL> answer = bottomUp.findSumFirstNaturalNums(LIMIT);

    LL n = 1;
    for(const LL sum : answer) {
        cout << "Sum of [1, " << n << "] is " << sum << '\n';
        n++;
    }

    return 0;
}