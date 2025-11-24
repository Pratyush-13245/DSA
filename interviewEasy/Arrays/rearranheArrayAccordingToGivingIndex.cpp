#include <bits/stdc++.h>

using namespace std;

void rearrannge(vector<int> arr,vector<int> index,int n , int z)
{

    vector<vector<int>> paired;
    for (int i = 0; i < arr.size(); i++) 
    {
        paired.push_back({index[i], arr[i]});
    }

    sort(paired.begin(),paired.end());
    for(int i=0;i<arr.size();i++)
    {
        arr[i] = paired[i][1];
    }
    cout<<"Printing Answer now"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return;
}

int main()
{

    vector<int> arr;
    cout<<"Please insert array size"<<endl;
    int n ;
    cin>> n;

    cout<<"Please insert elements of array"<<endl;

    for(int i=0;i<n;i++)
    {
        int c ;
        cin>>c;
        arr.push_back(c);
    }
    cout<<"Printing Original Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    
     vector<int> index;
    cout<<"Please insert index array size"<<endl;
    int z ;
    cin>> z;

     for(int i=0;i<n;i++)
    {
        int c ;
        cin>>c;
        index.push_back(c);
    }
    rearrannge(arr,index,n,z);

    return 0;
}