#include<iostream>
using namespace std;

class que
{
    int a[100];
    int front = -1;
    int rear=-1;
    
    friend class stack_using_queues;
    
    public:
    
    bool isfull()
    {
        if(rear==99)
        {
            return true;
        }
        
        else 
        {
            return false;
        }
    }
    
    bool isempty()
    {
        if((rear==-1 && front==-1) || (front>rear))
        {
            return true;
        }
        
        else 
        {
            return false;
        }
    }
    
    void insert(int data)
    {
        if(isfull())
        {
            cout<<"Queue is full"<<endl;
        }
        
        else 
        {
            rear++;
            a[rear]=data;
            
            if(rear==0)
            {
                front=0;
            }
        }
        
    }
    
    int del()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;
        }
        
        else 
        {
            return a[front++];
        }
    }
};

class stack_using_queues
{
    que q1,q2;
    public:
    void push(int element)
    {
        if(q1.isfull())
        {
            cout<<"Stack overflow"<<endl;
        }
        
        else 
        {
            q1.insert(element);
        }
    }
    
    void pop()
    {
        while(!q1.isempty())
        {
            int x = q1.del();
            
            if(!q1.isempty())
            {
                q2.insert(x);
            }
            
            else 
            {
                cout<<x<<endl;
            }
        }
    }
    
    void func()
    {
        q1.rear=-1;
        q1.front=-1;
        
        while(!q2.isempty())
    {
        q1.insert(q2.del());
    }
    
    q2.rear=-1;
    q2.front=-1;
    }
    
};

int main()
{
    char c;
    cout<<"Enter the operation you want to peform"<<endl;
    while(true)
    {
        
    }
    
    
    return 0;
}
