#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;
int c = 0;
void Heapify (int h[], int n)
{
  int heap, k, v, j;
  for (int i = (n/2); i >= 1; i--)
  {
    k = i;
    v = h[k-1];
    heap = 0;
    while (!heap && 2*k <= n){
      j = 2*k;
      //c++;
      if (j < n)
      {
        c++;
        if (h[j-1] < h[j])
            j++;
      }
      c++;
      if (v >= h[j-1])
        heap = 1;
      else{
        h[k-1] = h[j-1];
        k = j;
      }
    }
    h[k-1] = v;
  }
}
void Heapsort(int arr[], int n)
{
    int temp;
    for (int i = n; i > 1; i--){
      Heapify(arr,i);
      temp = arr[0];
      arr[0] = arr[i-1];
      arr[i-1] = temp;
    }
}
int main(){
  int i, n, a[MAX];
  c = 0;
  cout<<"\nRead Value of n (no. of elements) : ";
  cin>>n;
  cout<<"Enter the elements :-\n";
  for (i = 0; i < n; i++)
    cin>>a[i];
  //Heapify(a,n);
  Heapsort(a,n);
  cout<<"\nSorted Elements using Heapsort are : ";
  for (i = 0; i < n; i++) 
    cout<<a[i]<<" ";
  cout<<"\n\nNo. of Comparisions => "<<c;
  cout<<endl<<endl;
  return 0;
}
