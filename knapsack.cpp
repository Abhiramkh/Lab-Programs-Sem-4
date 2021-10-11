#include<bits/stdc++.h>
using namespace std;
int c;
int knapsack(int W,int w[],int v[],int ni)
{
	c++;
	if(W==0 or ni==0)
		return 0;
	if(w[ni]>W)//we have only one choice
	{
		return knapsack(W,w,v,ni-1);
	}
	else
		return max(knapsack(W,w,v,ni-1),v[ni]+knapsack(W-w[ni],w,v,ni-1));//max of value when we do not include the n-1th item and when we include it
}

int knapsack_TD(int j,int w[],int v[],int i,int **lookup_table)//i is the number of items and j is the weight cutoff
{
	c++;
	if(lookup_table[i][j]!=-1)
		return lookup_table[i][j];
	if(w[i]>j)
	{
		 lookup_table[i][j]=knapsack_TD(j,w,v,i-1,lookup_table);
	}
	else
	{
		 lookup_table[i][j]=max(knapsack_TD(j,w,v,i-1,lookup_table),v[i]+knapsack_TD(j-w[i],w,v,i-1,lookup_table));
	}
	return lookup_table[i][j];
}

int knapsack_BU(int W,int w[],int v[],int ni,int **table)
{
	int i,j;
	for(i=1;i<=ni;i++)
	{
		for(j=1;j<=W;j++)
		{
			c++;
			if(w[i]>j)table[i][j]=table[i-1][j];
			else
			{
			table[i][j]=max(table[i-1][j],v[i]+table[i-1][j-w[i]]);//w[i] because at each stage a new weight value pair unlocks
			}
		}
	}
	return table[ni][W];
}

void printtable(int ni,int W,int **table)
{
	cout<<"ni/W\t";int i,j;
	for(i=0;i<=W;i++)cout<<i<<"\t";
	for(i=0;i<=ni;i++)
	{
		cout<<"\n"<<i<<"\t";
		for(j=0;j<=W;j++)
			cout<<table[i][j]<<"\t";
	}
}
int main()
{
	int ni,i,j,W;
	cout<<"Enter the number of items : ";
	cin>>ni;
	int w[ni],v[ni];
	w[0]=v[0]=0;
	for(i=1;i<=ni;i++)
	{
		cout<<"Enter the weight and value of item "<<i<<" : ";
		cin>>w[i]>>v[i];
	}
	cout<<"Enter the cutoff weight : ";cin>>W;
	cout<<"Method 1 : Recursion\n";
	c=0;
	cout<<"Maximum value that can be put in a knapsack of capacity "<<W<<" : "<<knapsack(W,w,v,ni)<<"\n";
	cout<<"Recursion count : "<<c<<"\n\n";
	cout<<"Method 2 : Top Down using DP(Memoization)\n";
	c=0;
	int **lookup_table;
	lookup_table=new int*[ni+1];
	for(i=0;i<=ni;i++)
		lookup_table[i]=new int[W+1];
	for(i=0;i<=ni;i++)
	{
		for(j=0;j<W+1;j++)
		{
			if(i==0 or j==0)
			{lookup_table[i][j]=0;}
			else
			lookup_table[i][j]=-1;
		}
	}
	cout<<"Maximum value that can be put in a knapsack of capacity "<<W<<" : "<<knapsack_TD(W,w,v,ni,lookup_table)<<"\n";
	printtable(ni,W,lookup_table);
	cout<<"\nRecursion count : "<<c<<"\n\n";
	cout<<"Method 3 : Bottom Up Dp\n";
	c=0;
	int **table;
	table=new int*[ni+1];
	for(i=0;i<=ni;i++)
		table[i]=new int[W+1];
	for(i=0;i<=ni;i++)
	{
		for(j=0;j<W+1;j++)
		{
			if(i==0 or j==0)
			{table[i][j]=0;}
			else
			table[i][j]=-1;
		}
	}
	cout<<"Maximum value that can be put in a knapsack of capacity "<<W<<" : "<<knapsack_BU(W,w,v,ni,table)<<"\n";
	printtable(ni,W,table);
	cout<<"\nBottom Up count : "<<c<<"\n\n";
	return 0;
}
