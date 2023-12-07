#include <iostream>
#include <string>
#include <bits/stdc++.h>
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


int prefix(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }

    stk st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            int num1 = st.peek();
            st.pop();
            int num2 = st.peek();
            st.pop();

            st.push(num1 + num2);
        }
        else if (s[i] == '-')
        {
            int num1 = st.peek();
            st.pop();
            int num2 = st.peek();
            st.pop();

            st.push(num1 - num2);
        }
        else if (s[i] == '*')
        {
            int num1 = st.peek();
            st.pop();
            int num2 = st.peek();
            st.pop();

            st.push(num1 * num2);
        }
        else if (s[i] == '/')
        {
            int num1 = st.peek();
            st.pop();
            int num2 = st.peek();
            st.pop();

            st.push(num1 / num2);
        }
        else
        {
            st.push(s[i] - '0');
        }
    }
    return st.peek();
}
int main()
{
    string s;
    cout<<"Enter the string: "<<endl;
    cin>>s;
    cout <<"Answer is: " <<prefix(s) << endl;

    return 0;
}

