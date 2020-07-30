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
      count=0;
      array=new int[capacity];
      for(int i=0;i<capacity;i++)
      {
          count++;
          array[i]=t[i];
      }
  }
};
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
    int min=INT_MAX;
    if(h==NULL)
        return;
    
    int l=leftChild(h,i);
    int r=rightChild(h,i);
    
    if(l!=-1 && h->array[i]>h->array[l])
        min=l;
    else
        min=i;
    if(r!=-1 && h->array[min]>h->array[r])
        min=r;
    if(min!=i)
    {
        int tmp=h->array[i];
        h->array[i]=h->array[min];
        h->array[min]=tmp;
        percolateDown(h,min);
    }
}

void deleteH(Heap *h, int n)
{
    queue<int>q;
    int i=0,index;
    q.push(i);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        if(n==h->array[tmp])
        {
            index=tmp;
            break;
        }
        if((2*tmp+1)<h->capacity)
            q.push(2*tmp+1);
        if((2*tmp+2)<h->capacity)
            q.push(2*tmp+2);
        
    }
   
   h->array[index]=h->array[h->count-1];
    h->count--;
    percolateDown(h,index);
}

void print(Heap *h)
{
    for(int i=0;i<h->count;i++)
        cout<<h->array[i]<<" ";
}
int main()
{
    int t[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Heap *h=new Heap(t, 16);
    int n=7;
    print(h);
    cout<<endl<<"Delete node "<<n<<" from heap"<<endl;
    deleteH(h,n);
    print(h);
     
    return 0;
}
