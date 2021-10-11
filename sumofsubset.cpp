#include<bits/stdc++.h>
using namespace std;
int n;
void print(int set[],int k,int i)
{
	static int count=1;
	int m=k-pow(2,i);
	int j=0,a[n];
	while(m>0)
	{
		i--;
		if(m%2){a[j++]=set[i];}//odd numbers indicates that index has been chosen
		m=m/2;
	}
	cout<<"Subset "<<count++<<" : {";
	if(j==0)cout<<",";
	for(j--;j>=0;j--)
	{
		cout<<a[j]<<",";
	}
	cout<<"\b}\n";
}
void subsetsum(int set[],int sum,int sum_so_far,int k)//k is used for implementation
{
	
	if(sum_so_far>sum)return;
	int i=log2(k);//i is used for indexing
	if(sum==sum_so_far){print(set,k,i);return;}
	if(i==n)return;
	subsetsum(set,sum,sum_so_far+set[i],2*k+1);
	subsetsum(set,sum,sum_so_far,2*k);
}
int main()
{
	int i,sum;
	cout<<"Enter the number of elements in the set : ";
	cin>>n;
	cout<<"Enter the elements of the set : ";
	int set[n];
	for(i=0;i<n;i++)cin>>set[i];
	cout<<"Enter the sum : ";
	cin>>sum;
	cout<<"\nSet : {";
	for(i=0;i<n;i++)cout<<set[i]<<", ";
	cout<<"\b\b} and Sum = "<<sum<<"\n";
	cout<<"Subsets with the sum "<<sum<<" is : \n";
	subsetsum(set,sum,0,1);
	return 0;
}
