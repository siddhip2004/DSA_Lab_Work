#include <bits/stdc++.h> 

using namespace std;

void insert_sort(int *p, int n)
{
    int i;
    //int j=0;
    int key;
    for(int j=1; j<n;j++)
    {
        key=p[j];
        i=j-1;
        
        while(i>=0 && p[i]>key)
        {
            p[i+1]=p[i];
            i=i-1;
        }
        
        p[i+1]=key;
    }
}

void merge(int *arr, int p, int q, int r) {
  
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

 
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void mergeSort(int *arr, int l, int r) {
  if (l < r) {
    
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    
    merge(arr, l, m, r);
  }
}


void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}


// int main()
// {
//     ofstream file;
//     file.open("data.txt");

//     int input[8] = {100,1000, 5000, 10000, 50000, 70000, 100000, 120000};

//     for(int i=0; i<8; i++){
    

//     time_t start , end, start1, end1;

//     // int n;
//     // cout<<"Enter the size of array: ";
//     // cin>>n;
//     int arr[input[i]];
//     int arr1[input[i]];
//     //cout<<"Enter the elements"<<endl;
    

//     for(int k =input[i]; k>0; k--)
//     {
//         arr[input[i]-k]=k;
//     }

//     for(int j =input[i]; j>0; j--)
//     {
//         arr1[input[i]-j]=j;
//     }

//     cout<<"Using insertion sort:"<<endl;
//     time(&start);
//     ios_base::sync_with_stdio(false); 

//     insert_sort(arr,input[i]);
//     time(&end);

//     printArray(arr, input[i]);

//     double time_taken = double(end - start); 
//     file << "Insertion sort ->  size = "<<input[i]<<",     time : " << fixed 
//         << time_taken << setprecision(5); 
//     file << " sec " << endl; 

//     cout<<"Using Merge sort:"<<endl;

//     time(&start1);
//     ios_base::sync_with_stdio(false); 

//     mergeSort(arr1, 0, input[i] - 1);
//     time(&end1);

//     printArray(arr1, input[i]);

//     double time_taken1 = double(end1 - start1); 
//     file << "Merge sort     ->  size = "<<input[i]<<",     time : " << fixed 
//         << time_taken1 << setprecision(5); 
//     file << " sec " << endl; 
//     // file<<input[i];
    
//     }



  
    

//     return 0;
// }

