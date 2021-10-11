#include<bits/stdc++.h>
using namespace std;
class graph{
public:
	map<int,bool>visited;//to keep a tab on the vertices visited
	map<int,list<int>>adj;// to keep a list of the adjacent vertices to a vertice
	void add_edge(int v, int w);
	void dfs_helper(int v);
	void dfs();
	int no_of_components;
	void bfs(int s);
};
void graph::add_edge(int v,int w){
	adj[v].push_back(w);//add the vertice to adjacency list
	adj[w].push_back(v);//to ensure it is a undirected graph
}
void graph::dfs_helper(int v)
{
	visited [v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
			dfs_helper(*i);
	}
}
void graph::dfs()
{
	for(auto i:adj)
		if(!visited[i.first])
		{
			cout<<"Component "<<++no_of_components<<" : ";
			dfs_helper(i.first);
			cout<<endl;
		}
}
void graph::bfs(int s){
	queue<int>q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int v=q.front();
		cout<<v<<" ";
		q.pop();
		for(auto i:adj[v])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i]=true;
			}
		}
	}
}


int main()
{		
	graph g;
	cout<<"Enter the number of edges in the graph : ";
	int i,n,a,b,first;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the vertices of edge number "<<i+1<<" : ";
		cin>>a>>b;
		if(i==0)first=a;
		g.add_edge(a,b);
	}
	cout<<"Enter 1 for dfs 2 for bfs : ";
	int ch;cin>>ch;
	if(ch==1){
	g.no_of_components=0;
	cout<<"Following is the Depth First Traversal : "<<endl;
	g.dfs();}
	else
	{
	cout<<"Following is the Breadth First Traversal : "<<endl;
	g.bfs(first);
	cout<<endl;
	}
	
	return 0;
}
