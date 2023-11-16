#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class stk
{
    int top = -1;
    int arr[100];

public:
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == sizeof(arr) / sizeof(arr[0]) - 1);
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack overflow " << endl;
            return;
        }
        arr[++top] = data;
    }
    int getSize()
    {
        return top + 1;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top];
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


