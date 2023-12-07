#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

struct node * start=NULL;

void  create (int n)
{
    for(int i=0; i<n; i++){
        
    
    int a;
    node *p, *q,*r;
    
    
    r=(node*)malloc(sizeof(node));
    
    cout<<"Enter value of counter "<<i+1<<endl;
    cin>>a;
    
    r->data = a;
    r->next = NULL;
    
    if(start == NULL)
    {
        start = r;
        r->next = NULL;
    }
    
    else 
    {
        
       q=start;
       p=q->next;
   
   
    
    while(p!=NULL)
    {
        if(r->data<q->data && r->data>p->data)
        {
            r->next=p;
            q->next=r;
            break;
        }
        
        else if(r->data>q->data && q==start)
        {
            r->next=q;
            start=r;
            break;
        }
        
        else 
        {
            q=p;
            p=p->next;
        }
    }
    
    if(r->data<q->data && p==NULL)
    {
        r->next=NULL;
        q->next=r;
    }
    
    else if(r->data>q->data && p==NULL)
    {
        r->next=q;
        start=r;
    }
       
       
  }
}
    
   
    
}

void display()
{
    node *m=(node*)malloc(sizeof(node));
    m=start;
    cout<<"The first element in the maximum priority queue is "<<m->data<<endl;
}

int main()
{
    int d;
    cout<<"Enter the total no. of elements of the maximum priority list"<<endl;
    cin>>d;
    create(d);
    display();
}


