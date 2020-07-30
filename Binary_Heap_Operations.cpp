#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//heap_type=1(max heap) heap_type=0(min heap)
class Heap
{
    public:
        int *array;
        int count,capacity,heap_type;
};

Heap *createHeap(int capacity, int heap_type)
{
    Heap *h=new Heap();
    if(h==NULL)
        cout<<"Memory Error"<<endl;
    h->capacity=capacity;
    h->heap_type=heap_type;
    h->count=0;
    h->array=new int[capacity];
    if(h->array==NULL)
        cout<<"Memory Error"<<endl;
        
    return h;
}

void resizeHeap(Heap *h)
{
    int *old_array=h->array;
    h->array=new int[h->capacity*2];
    for(int i=0;i<h->capacity;i++)
        h->array[i]=old_array[i];
        
    h->capacity=h->capacity*2;
    delete(old_array);
}

void Insertion(Heap *h, int data)
{
    int i;
    if(h->count==h->capacity)
        resizeHeap(h);
    h->count++;
    i=h->count-1;
    while(i>0 && data>h->array[(i-1)/2])
    {
        h->array[i]=h->array[(i-1)/2];
        i=(i-1)/2;
    }
    h->array[i]=data;
}

int leftChild(Heap *h, int i)
{
    int l=2*i+1;
    if(h->count==0 || l>=h->count)
        return -1;
    return l;
}
int rightChild(Heap *h, int i)
{
    int r=2*i+2;
    if(h->count==0 || r>=h->count)
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

void Deletion(Heap *h)
{
    int data;
    if(h->count==0)
        return;
    h->array[0]=h->array[h->count-1];
    h->count--;
    percolateDown(h,0);
}

void print(Heap *h)
{
     for(int i=0;i<h->count;i++) 
     {
         cout<<h->array[i]<<" ";
     }
}

int main()
{
    Heap *h;
    //creating heap
    h=createHeap(11,1);
    //Insertion;
    Insertion(h,31);
    Insertion(h,10);
    Insertion(h,16);
    Insertion(h,9);
    Insertion(h,8);
    Insertion(h,14);
    Insertion(h,12);
    Insertion(h,3);
    Insertion(h,1);
    Insertion(h,5);
    Insertion(h,7);
    Insertion(h,19);
    cout<<"Heap containta are"<<endl;
    print(h);
    cout<<endl<<"Deletion"<<endl;
    Deletion(h);
    print(h);
    
    return 0;
}
