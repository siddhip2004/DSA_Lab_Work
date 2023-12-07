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
    node *p,*r;
    p=start;
    int round_time=0;
    cout<<"Processor Id     Execution time    Round-around-time"<<endl;
   while(start!=NULL)
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
            if(p->next==p) {
                start=NULL;
                break;
            }
            else p=p->next;
        }
        
        else if(p->data<exetime)
        {
            r=p;
            round_time=round_time+p->data;
            cout<<p->id<<"                 "<<p->data<<"                       "<<round_time<<endl;
            p->data=0;
            del(r);
            if(p->next==p) {
                start=NULL;
                break;
            }
            else p=p->next;
        }
        
    
    }
    
}

int main()
{
    int n=0;
    cout<<"Enter the no. of Processors you want: ";
    cin>>n;
    
    create(n);
    execute();
}





