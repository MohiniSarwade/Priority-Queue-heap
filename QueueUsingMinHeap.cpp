#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
        int c;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        Queue()
        {
            c=1000;
        }
};

void enqueue(Queue *q, int data)
{
    q->p.push(make_pair(q->c++,data));
}

void Dequeue(Queue *q)
{
    if(q->p.empty())
        cout<<"Nothing to pop"<<endl;
    q->p.pop();
    q->c--;
    cout<<"Top element has been popped"<<endl;
}

void front(Queue *q )
{
    cout<<"Top of the stack is ";
    cout<<q->p.top().second<<endl;
}
int main()
{
   Queue *s=new Queue();
   enqueue(s,6);
   enqueue(s,3);
   enqueue(s,2);
   front(s);
   Dequeue(s);
   front(s);

    return 0;
}
