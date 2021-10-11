#include <stdio.h>
int c=0;
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
   // Your code here
   int i=low-1;
   int j=0;
   c=c+(high-low+1);
   for(j=0;j<=high-low;j++)
   {
       if(arr[j+low]<arr[high])
       {
           i++;
           swap(&arr[i],&arr[j+low]);
       }
   }
   swap(&arr[i+1],&arr[high]);
   return i+1;
}
int main()
{	
   int n,j;
   printf("Enter the number of elements in the array\n");
   scanf("%d",&n);
   int arr[n];
   for(j=0;j<n;j++)
   {
       arr[j]=(int)rand()%1000;
   }
   for(j=0;j<n;j++)
   {
       printf("%d ",arr[j]);
   }
   printf("\n");
   quickSort(arr,0,n-1);	
   for(j=0;j<n;j++)
   {
       printf("%d ",arr[j]);
   }
   printf("\nTimme taken is : %d",c);
}