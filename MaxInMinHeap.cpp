#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap
{
    public:
    int count, capacity;
    int *array;
    
    Heap(int n, int t[])
    {
        capacity=n;
        count=0;
        array=new int[n];
        for(int i=0;i<capacity;i++)
        {
                array[i]=t[i];
                count++;
        }
        
    }
};

int MaxInMinHeap(Heap *h)
{
    int max=-1;
    for(int i=(h->count+1)/2;i<h->count;i++)
    {
       
        if(h->array[i]>max)
            max=h->array[i];
    }
    return max;
}
int main()
{
    int t[12]={1,5,14,2,10,21,18,3,11,28,37,42};
   
    Heap *h=new Heap(12,t);
    
    cout<<"Maximum element from the min heap is "<<MaxInMinHeap(h)<<endl;
    
}
