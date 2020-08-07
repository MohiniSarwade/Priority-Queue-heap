#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void MaxSumSlidingWindow(int arr[],int k,vector<int>&v,int n)
{
    deque<int>q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && arr[i]>=arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
   
    for(int i=k;i<n;i++)
    {
        v.push_back(arr[q.front()]);
        while(!q.empty() && arr[i]>=arr[q.back()])
            q.pop_back();
        while(!q.empty() && q.front()<=i-k)
            q.pop_front();
        q.push_back(i);
    }
    v.push_back(arr[q.front()]);
}

int main()
{
    int arr[]={12,1,78,90,57,89,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    int k=3;
    cout<<"Max Sliding window sum"<<endl;
    MaxSumSlidingWindow(arr,k,v,n);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}
