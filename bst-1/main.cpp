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

void preorder(struct node *p)
{
    stack<node*>st;
    //node *p = (struct node *)malloc(sizeof(struct node));
    node *a=NULL;
    p=root;
    //a=p;
    //st.push(p->data);
    
    cout<<"Preorder traversal is: ";
    
    while(!st.empty() || p!=NULL)
    {

     if(p!=NULL)
        {
            cout<<p->data<<" ";
            st.push(p);
            p=p->left;
        }
        
      else 
      {
          a=st.top();
          st.pop();
          p=a->right;
      }
        
    }
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

bool check(root)
{
    if(root!=NULL)
    {
        if((root->left!=NULL && root->right !=NULL) || (root->left==NULL || root->right==NULL))
        {
            check(root->left);
            check(root->right);
        }
        
        else 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    create(10);
    create(20);
    create(5);
    inorder(root);
    search (10);
    preorder(root);
    check(root);
    return 0;
}






