#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Heap
{
  public:
  int capacity,count;
  int *array;
  Heap(int t[],int size)
    {
        capacity=size;
        count=0;
        array=new int[capacity];
        for(int i=0;i<capacity;i++)
        {
            
            count++;
            array[i]=t[i];
        }
    }
  
};

void resizeHeap(Heap *h)
{
    if(h==NULL)
        return;
    int *old_arr=h->array;
    h->array=new int[h->capacity*2];
    for(int i=0;i<h->capacity;i++)
        h->array[i]=old_arr[i];
    h->capacity*=2;
    delete(old_arr);
    
}
int FindkthSmallest(Heap *h, int k)
{
   
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    
    p.push(make_pair(h->array[0],0));
    
    for(int i=0;i<k-1;i++)
    {
        int j=p.top().second;
        int l=2*j+1,r=2*j+2;
        p.pop();
        if(l<h->count)
          p.push(make_pair(h->array[l],l));
        if(r<h->count)
            p.push(make_pair(h->array[r],r));
    }
    return p.top().first;
    
}
void print(Heap *h)
{
    for(int i=0;i<h->count;i++)
        cout<<h->array[i]<<" ";
}
int main()
{
    int t[7]={10,50,40,75,60,65,45};
    Heap *h=new Heap(t,7);
    int k=5;
    print(h);
    cout<<endl<<k<<"th smallest elemrnt in the heap: "<<FindkthSmallest(h,k);
    
        
    return 0;
}
