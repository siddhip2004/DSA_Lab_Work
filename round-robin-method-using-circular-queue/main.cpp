#include<iostream>
using namespace std;

struct node
{
    string id;
    int data;
    struct node *next;
};

int exetime=4;
struct node *start;


void create(int n)
{
    string s;
    int ptime;
    node*p, *q;
    start = NULL;
    
    for(int i=1; i<=n; i++)
    {
        p=(node*)malloc(sizeof(node));
        cout<<"Enter the name of processor "<<i<<" and its execution time"<<endl;
        cin>>s>>ptime;
        p->id=s;
        p->data=ptime;
        
        if(start==NULL)
        {
            
            p->next=p;
            start=p;
        }
        
        else
        {
            q=start;
            while(q->next!=start)
            {
                q=q->next;
            }
            
            q->next=p;
            p->next=start;
        }
        
        cout<<endl;
    }
}
void del(node *p)
{
    node *q;
    node *r = start;
    q=p;
    if(q->next==start)
    {
        while(r->next!=q)
        {
            r=r->next;
        }
        
        r->next=start;
        free(q);
    }
    
    else if(q==start)
    {
        while(r->next!=start)
        {
            r=r->next;
        }
        
        start=q->next;
        r->next=start;
        free(q);
    }
    
    else 
    {
        while(r->next !=q)
        {
            r=r->next;
        }
        
        r->next=q->next;
        free(q);
    }
    
}

void execute()
{
    //while(start!=NULL){
    
    node *p,*r;
    p=start;
    int round_time=0;
    cout<<"Processor Id     Execution time    Round-around-time"<<endl;
   while(p->next!=NULL)
    {
        if(p->data>exetime)
        {
            p->data=p->data-exetime;
            round_time=round_time+exetime;
            cout<<p->id<<"                 "<<exetime<<"                       "<<round_time<<endl;
            p=p->next;
        }
        
        else if(p->data == exetime)
        {
            r=p;
            p->data =0;
            round_time=round_time+exetime;
            cout<<p->id<<"                 "<<exetime<<"                       "<<round_time<<endl;
            del(r);
            p=p->next;
        }
        
        else if(p->data<exetime)
        {
            r=p;
            round_time=round_time+p->data;
            cout<<p->id<<"                 "<<p->data<<"                       "<<round_time<<endl;
            p->data=0;
            del(r);
            p=p->next;
        }
        
    
    }
    
        /*if(p->data>exetime)
        {
            p->data=p->data-exetime;
            cout<<"Execution time for "<<p->id<<" is "<<exetime<<endl;
            p=p->next;
        }
        
        else if(p->data == exetime)
        {
            r=p;
            p->data =0;
            cout<<"Execution time for "<<p->id<<" is "<<exetime<<endl;
            del(r);
            p=p->next;
        }
        
        else if(p->data<exetime)
        {
            r=p;
            cout<<"Execution time for "<<p->id<<" is "<<p->data<<endl;
            p->data=0;
            del(r);
            p=p->next;
        }*/
    
//}
    
}

int main()
{
    
    create(3);
    execute();
    
}



