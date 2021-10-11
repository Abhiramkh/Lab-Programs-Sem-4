#include<stdio.h>
int c=0;
void merge(int arr[],int l,int m,int r)
{
    c=c+(r-l+1);
    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=r-m;
    int left[n1],rig[n2];
    for(i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        rig[j]=arr[m+1+j];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(left[i] <= rig[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=rig[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
            i++;
            k++;
    }
    while(j<n2)
    {
        arr[k]=rig[j];
            j++;
            k++;
    }
}
void mergesort(int arr[],int l,int r)
{
    if(l>=r)
    return;
    int m=(l+r)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
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
   mergesort(arr,0,n-1);
   for(j=0;j<n;j++)
   {
       printf("%d ",arr[j]);
   }
   printf("\nTimme taken is : %d",c);
}
