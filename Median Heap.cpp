#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap
{
    public:
        int c;
        priority_queue<pair<int,int>>pq_LMax;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq_RMin;

    Heap()
    {
        c=0;
    }
};

float getMedian(int e,float &m,priority_queue<pair<int,int>> &lMax,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>& rMin,int c)
{
    int ch=lMax.size()-rMin.size();
    switch(ch)
    {
        case 0:
            if(e<m)
            {
                lMax.push(make_pair(e,c++));
                m=lMax.top().first;
            }
            else
            {
                rMin.push(make_pair(e,c++));
                m=rMin.top().first;
            }
            break;
        case 1:
            if(e<m)
            {
                rMin.push(make_pair(lMax.top().first,c++));
                lMax.pop();
                c--;
                lMax.push(make_pair(e,c++));
            }
            else
            {
                rMin.push(make_pair(e,c++));
            }
            m=(rMin.top().first + lMax.top().first)/2;
            break;
            
        case -1:
            if(e<m)
            {
                lMax.push(make_pair(e,c++));
            }
            else
            {
                lMax.push(make_pair(rMin.top().first,c++));
                rMin.pop();
                c--;
                rMin.push(make_pair(e,c++));
            }
            m=(rMin.top().first+lMax.top().first)/2.0;
            break;
    }
    //cout<<m<<endl;
    return m;
}

float Median(int t[], int n)
{
    Heap *h=new Heap();
    
    float m=0;
    for(int i=0;i<n;i++)
        getMedian(t[i],m,h->pq_LMax,h->pq_RMin,h->c);
        
    return m;
    
}

int main()
{
    
    int t[9]={1,8,2,2,3,4,5,5,8};
    cout<<"Median of the heap is "<<Median(t,9)<<endl;
    return 0;
}
