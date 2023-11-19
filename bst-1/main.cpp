#include<iostream>
#include"stack"
using namespace std;


struct node
{
    int data;
    struct node *left, *right;
};
struct node *root=NULL;


void create(int q)
{
    
    node *r=(struct node *)malloc(sizeof(struct node));
    r->data=q;
    r->right=NULL;
    r->left=NULL;
    node *p,*a;
    
    if(root==NULL)
    {
        root=r;
        //save=root;
    }
    
    
    
    else 
    {
        p=root;
        
        while(true)
        {
            a=p;
            
            if(a->data<q)
            {
                p=p->right;
                
                if(p==NULL)
                {
                    a->right=r;
                    return;
                }
            }
            
            else 
            {
                p=p->left;
                
                if(p==NULL)
                {
                    a->left=r;
                    return;
                }
            }
        }
        
    }
}

void inorder(struct node* m)
{
    if(m!=NULL){
    inorder(m->left);
    cout<<m->data<<" ";
    inorder(m->right);
    }
    
    //cout<<endl;
}

void preorder()
{
    stack<int>st;
    node *p = (struct node *)malloc(sizeof(struct node));
    node *a;
    p=root;
    a=p;
    st.push(p->data);
    
    while(!st.empty())
    {
        
        
        if(p->left!=NULL)
        {
            cout<<st.top();
            st.pop();
            a=p;
            p=a->left;
            st.push(p->data);
            continue;
        }
        
        else if(p->left==NULL && p->right!=NULL)
        {
            cout<<st.top();
            st.pop();
            a=p;
            p=p->right;
            st.push(p->data);
            continue;
        }
        
        else
        
    }
    // while(p->left!=NULL)
    // {
        
    // }
    
}

void search(int key)
{
    node *p=(struct node *)malloc(sizeof(struct node)); 
    p=root;
    
    if(root==NULL)
    {
        cout<<"\nTree is empty"<<endl;
    }
    
    else{
    while(p!=NULL)
    {
        if(p->data<key)
        {
            p=p->right;
            
            if(p==NULL)
            {
                cout<<"\nNo such value in the tree"<<endl;
            }
        }
        
        else if(p->data>key)
        {
            p=p->left;
            
            if(p==NULL)
            {
                cout<<"\nNo such value in the tree"<<endl;
            }
        }
        
        else if(p->data==key)
        {
            cout<<"\nValue exists"<<endl;
            break;
        }
    }
    
    //return p;
    }
    
    //return p;
}

int main()
{
    create(10);
    create(20);
    create(5);
    inorder(root);
    search (10);
    preorder();
    return 0;
}




