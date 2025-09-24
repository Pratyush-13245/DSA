#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lis(vector<int>& nums, int cur) {
        if (cur == 0) {
            return 1;
        }
        int ans = 1;
        for (int i = cur - 1; i >= 0; i--) {  // fixed: >=0 instead of >0
            if (nums[i] < nums[cur]) {
                ans = max(ans, 1 + lis(nums, i));
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, lis(nums, i));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 2, 3};

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    int result = sol.lengthOfLIS(nums);
    cout << "Length of LIS = " << result << endl;

    return 0;
}
