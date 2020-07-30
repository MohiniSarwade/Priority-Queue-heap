#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Heap{
  public:
  int *array;
  int count, capacity;
};

Heap *createHeap(int n)
{
    Heap *h=new Heap();
    if(n==0)
        return NULL;
    h->capacity=n;
    h->count=0;
    h->array=new int[n];
    return h;
}
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
int leftChild(Heap *h,int i)
{
    int l=2*i+1;
    if(l>=h->count)
        return -1;
    return l;
}

int rightChild(Heap *h, int i)
{
    int r=2*i+2;
    if(r>=h->count)
        return -1;
    return r;
}
void percolateDown(Heap *h, int i)
{
    int l=leftChild(h,i);
    int r=rightChild(h,i);
    int max;
    if(l!=-1 && h->array[i]<h->array[l])
        max=l;
    else
        max=i;
    if(r!=-1 && h->array[max]<h->array[r])
        max=r;
    if(max!=i)
    {
        int tmp=h->array[i];
        h->array[i]=h->array[max];
        h->array[max]=tmp;
        percolateDown(h,max);
    }
}

void buildHeap(Heap *h,int t[], int n)
{
    if(h==NULL)
        return;
    while(n>h->capacity)
        resizeHeap(h);
    for(int i=0;i<n;i++)
    {
        h->array[i]=t[i];
    }
    h->count=n;
    for(int i=(n-1)/2;i>=0;i--)
        percolateDown(h,i);
}

void HeapSort(int t[], int n)
{
    Heap *h=createHeap(n);
    buildHeap(h,t,n);
    int old_size=h->count;
    for(int i=n-1;i>=0;i--)
    {
        int tmp=h->array[0];
        h->array[0]=h->array[h->count-1];
        h->array[h->count-1]=tmp;
        t[h->count-1]=tmp;
        h->count--;
        percolateDown(h,0);
        
    }
    
}
void printHeap(int t[], int n)
{
   for(int i=0;i<n;i++)
    cout<<t[i]<<" ";
}
int main()
{
     int t[12]={31,10,19,9,8,16,12,3,1,5,7,14};
    cout<<"Original Array"<<endl;
    printHeap(t,12);
    cout<<endl<<"Sorted array using HeapSort"<<endl;
   
    HeapSort(t,12);
    printHeap(t,12);
}
