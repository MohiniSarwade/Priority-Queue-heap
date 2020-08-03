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

void resize(Heap *h1,int n)
{
    if(h1==NULL)
        return;
    int *old_arr=h1->array;
    h1->array=new int[h1->capacity+n];
    for(int i=0;i<h1->capacity;i++)
        h1->array[i]=old_arr[i];
        
    h1->capacity+=n;
    delete(old_arr);
}
int leftChild(Heap *h,int i)
{
    int l=2*i+1;
    if(l>=h->count)
        return -1;
    return l;
}
int rightChild(Heap *h,int i)
{
    int r=2*i+2;
    if(r>=h->count)
        return -1;
    return r;
}
void heapify(Heap *h1,int i)
{
    int l=leftChild(h1,i);
    int r=rightChild(h1,i);
    int max=INT_MIN;
    if(l!=-1 && h1->array[l]>h1->array[i])
        max=l;
    else
        max=i;
    if(r!=-1 && h1->array[max]<h1->array[r])
        max=r;
    
    if(max!=i)
    {
        int tmp=h1->array[i];
        h1->array[i]=h1->array[max];
        h1->array[max]=tmp;
        heapify(h1,max);
    }
    
}
void print(Heap *h)
{
    for(int i=0;i<h->count;i++)
        cout<<h->array[i]<<" ";
}
void mergingMaxHeaps(Heap *h1,Heap *h2)
{
   resize(h1,h2->capacity);
   int m=h1->count;
   for(int i=0;i<h2->capacity;i++)
    {
        h1->array[m+i]=h2->array[i];
        h1->count++;
    }
    cout<<endl<<"before heapify"<<endl;
     print(h1);
     int n=h1->count;
    for(int i=(n-1)/2;i>=0;i--)
        heapify(h1,i);
}
int main()
{
    int t[7]={11,8,4,0,7,1,3};
    Heap *h1=new Heap(t,7);
    cout<<"Heap 1 "<<endl;
    print(h1);
    int m[7]={13,10,12,9,6,2,5};
    Heap *h2=new Heap(m,7);
    cout<<endl<<"Heap 2 "<<endl;
    print(h2);
    mergingMaxHeaps(h1,h2);
     cout<<endl<<"Elements after merging in the heap: "<<endl;
    print(h1);
        
    return 0;
}
