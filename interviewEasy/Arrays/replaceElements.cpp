#include <bits/stdc++.h>

using namespace std;

vector<int> replaceElements(vector<int> &arr,int n)
{
    int greatest = -1;

    for(int i=n-1;i>=0;i--)
    {
        int current = arr[i];
        arr[i] = greatest;
        greatest = max(greatest,current);
    }
    return arr;
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
    replaceElements(arr, n);

     cout<<"Printing answer Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}