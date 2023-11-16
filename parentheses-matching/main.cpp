#include<iostream>
#include<string>
using namespace std;

class stk
{
  char arr1[100];
  int top;
  
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
  
  
  void push(char data)
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
 
   char pop()
   {
       if(isempty())
       {
           cout<<"Stock Underflow"<<endl;
           return 0;
       }
       
       else 
       {
           int m = arr1[top];
           //arr1[top]=NULL;
           top--;
           return m;
       }
   }
   
   char peek()
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
    stk s;
    string expression;
    int r1=0;
    int r2=0;
    cout<<"Enter the expression"<<endl;
    cin>>expression;
    int x=expression.length();
    for(int i=0;i<x;i++)
    {
        if((expression[i] == '{') || (expression[i] == '(') || (expression[i] == '['))
        {
            s.push(expression[i]);
            r1++;
        }
        
        else if((expression[i] == '}' && s.peek() == '{') || (expression[i] == ')' && s.peek() == '(') || (expression[i] == ']' && s.peek() == '['))
        {
            s.pop();
            r2++;
        }
        
        else if( ((expression[i] == '}') || (expression[i] == ')') || (expression[i] == ']')) && (s.isempty()) )
        {
            r2=0;
        }
        
        else if((expression[i] == '}' && s.peek() != '{') || (expression[i] == ')' && s.peek() != '(') || (expression[i] == ']' && s.peek() != '['))
        {
            s.push(expression[i]);
            r2=0;
        }
    }
    
    if((r1==r2) && s.isempty())
    {
        cout<<"Valid Expression"<<endl;
    }
    
    else 
    {
        cout<<"Invalid Expression"<<endl;
    }
    
}
    
    
    


