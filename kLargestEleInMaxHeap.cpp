#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Heap
{
  public:
  int *array;
  int count, capacity;
  
  Heap(int t[], int n)
  {
      capacity=n;
      array=new int[capacity];
      count=0;
      for(int i=0;i<n;i++)
      {
          count++;
          array[i]=t[i];
      }
  }
};

void FindkMaxEle(Heap *h, int k)
{
    priority_queue<pair<int,int>>p;
    p.push(make_pair(h->array[0],0));
  
    for(int i=0;i<k;i++)
        {
            
            int j=p.top().second;
            cout<<p.top().first<<" ";
            int l=2*j+1;
            int r=2*j+2;
           
            p.pop();
           
            if(l<h->count)
            {   
               
                p.push(make_pair(h->array[l],l));
            }
            
            if(r<h->count)
            {
                p.push(make_pair(h->array[r],r));
            }
            
        }
    
}

void print(Heap *h)
{
    for(int i=0;i<h->count;i++)
        cout<<h->array[i]<<" ";
}
int main()
{
    int t[7]={13,12,6,10,11,4,5};
    Heap *h=new Heap(t,7);
    int k=5;
    print(h);
    cout<<endl<<k<<" max elemnts in the heap: "<<endl;
    FindkMaxEle(h,k);

    return 0;
}
