#include<iostream>
using namespace std;

class stk
{
  int top;
  int arr1[100];
 
  public :
  
  stk()
  {
      top=-1;
  }
 
  bool isfull()
  {
      if(top==99)
      {
          return 1;
      }
     
      else
      {
         return 0;
      }
  }
 
  bool isempty()
  {
      if(top==-1)
      {
          return 1;
      }
     
      else
      {
          return 0;
      }
  }
  
  bool cond1()
  {
      char a='y';
      char b='n';
      char c;
      
      cout<<"Do you want to enter the number (y/n)"<<endl;
      cin>>c;
      
      if(c==a)
      {
          cout<<"Enter the digit"<<endl;
          return 1;
      }
      
      else if(c==b)
      {
          //break;                                                      //cannot use here
          return 0;
      }
      
      else 
      {
          cout<<"ERROR: INVALID INPUT"<<endl;
          return 0;
      }
  }
  
  void push(int data)
  {
      if(isfull())
      {
         cout<<"Stack Overflow"<<endl;
      }
     
      else
      {
          top = top+1;
          arr1[top]=data;
      }
  }
 
   int pop()
   {
       if(isempty())
       {
           cout<<"Stock Underflow"<<endl;
           return 0;
       }
       
       else 
       {
           return arr1[top--];
       }
   }
   
   int peek()
   {
       if(isempty())
       {
           cout<<"Stack Underflow"<<endl;
           return 0;
       }
       
       else
       {
           return arr1[top];
       }
       
   }
};

int main()
{
    int d;
    stk s,s1,s2;
    
    cout<<"For the first large no."<<endl;
    while(s.cond1())
    {
         cin>>d;
         s.push(d);
    }
    
    cout<<"For the second large no."<<endl;
    while(s1.cond1())
    {
        cin>>d;
        s1.push(d);
    }
    
    
    int e,f,g,q,r,x;
    int carry=0;
    
    while((!s1.isempty()) && (!s.isempty()))
    {
        f=s.pop();
        g=s1.pop();
        e=f+g+carry;
        if(e>=10)
        {
            r=e%10;
            q=e/10;
            carry=q;
            s2.push(r);
        }
        else{
        s2.push(e);}
        
    }
    
    while(!s1.isempty())
    {
        f=s.pop();
        //g=s1.pop();
        e=f+carry;
        if(e>=10)
        {
            r=e%10;
            q=e/10;
            carry=q;
            s2.push(r);
        }
        else{
        s2.push(e);}
    }
    
    while(!s.isempty())
    {
        //f=s.pop();
        g=s1.pop();
        e=g+carry;
        if(e>=10)
        {
            r=e%10;
            q=e/10;
            carry=q;
            s2.push(r);
        }
        else{
        s2.push(e);}
    }
    
    if(carry==1)
    {
        s2.push(1);
    }
    
    cout<<"The sum of 2 large no.s entered is: ";
    
    while(!s2.isempty())
    {
        cout<<s2.pop();
    }
    
    
    
}
	


