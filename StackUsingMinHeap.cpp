#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
        int c;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        Stack()
        {
            c=1000;
        }
};

void push(Stack *s, int data)
{
    s->p.push(make_pair(s->c--,data));
}

void pop(Stack *s)
{
    if(s->p.empty())
        cout<<"Nothing to pop"<<endl;
    s->p.pop();
    s->c++;
    cout<<"Top element has been popped"<<endl;
}

void top(Stack * s )
{
    cout<<"Top of the stack is ";
    cout<<s->p.top().second<<endl;
}
int main()
{
   Stack *s=new Stack();
   push(s,6);
   push(s,3);
   push(s,2);
   top(s);
   pop(s);
   top(s);

    return 0;
}
