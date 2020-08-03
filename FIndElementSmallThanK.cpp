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

void FindElementLessThan(Heap *h, int k,int i)
{
    if(i<h->capacity)
    {
        if(h->array[i]<k)
            cout<<h->array[i]<<" ";
        FindElementLessThan(h,k,2*i+1);
        FindElementLessThan(h,k,2*i+2);
    }
 
}
void print(Heap *h)
{
    for(int i=0;i<h->count;i++)
        cout<<h->array[i]<<" ";
}
int main()
{
    int t[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Heap *h=new Heap(t,16);
    int k=12;
    print(h);
    cout<<endl<<"Elements Less Than "<<k<<" in the heap: "<<endl;
    FindElementLessThan(h,k,0);
    
        
    return 0;
}
