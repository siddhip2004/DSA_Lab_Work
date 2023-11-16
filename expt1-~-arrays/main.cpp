#include<iostream>
using namespace std;


void input(int a[], int size)
{
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>a[i];
    }
}
void output(int b[],int size)
{
    cout<<"Displaying elements"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<b[i]<<" ";
    }
}

void search(int c[], int size)
{
    int element;
    int n=0;
    int i = 0;
    cout<<"\nEnter the element you want to search"<<endl;
    cin>>element;
   
    for(i=0; i<size; i++)
    {
        if(c[i] == element)
        {
           n=1;
           break;
        }
       
        else
        {
            n=0;
           
        }
    }
   
    if(n==1)
    {
         cout<<"Element "<<element<<" is at index "<<i<<" of the array"<<endl;
    }
   
    else
    {
        cout<<"No such element exists in the array"<<endl;
    }
}

void sort(int d[],int size)
{
    cout<<"The array sorted in ascending array is"<<endl;
   
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(d[i] > d[j])
            {
                int temp;
                temp = d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }
   
    for(int i=0; i<size; i++)
    {
        cout<<d[i]<<" ";
    }
}

void del(int e[], int size)
{
    // int num;
    // cout<<"Enter the number of elements you want to delete"<<endl;\
    // cin>>num;
   
    int index;
    cout<<"\nEnter the index no. of the array you want to delete"<<endl;
    cin>>index;
   
    for(int i=0; i<size-1; i++)
    {
        e[index+i] = e[index+i+1];
    }
   
    //size = size - 1;
   
    cout<<"Displaying elements"<<endl;
    for(int i=0; i<size-1; i++)
    {
        cout<<e[i]<<" ";
    }
}
void insert(int f[], int size)
{
  int index;
   int ele;
   
  cout<<"\nEnter the no. you want to insert"<<endl;
  cin>>ele;
  cout<<"Enter the index no. where you want to insert"<<endl;
  cin>>index;
   size = size+1;
  for(int i=1; i<=((size-1)-index); i++)
  {
      f[size-i]=f[size-(i+1)];
  }
 
  f[index]=ele;
 
  cout<<"Displaying elements after insertion"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<f[i]<<" ";
    }
 
 
}

int main()
{
    int size=0;
   
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
   
    int arr[size];
   
   
    input(arr,size);
   
   
   
    output(arr,size);
    search(arr,size);
    sort(arr,size);
    del(arr,size);
    insert(arr,size);
       
}