#include <iostream>
#include <stdlib.h>
#define INF 999
using namespace std;
void Dijkstras (int n, int cost[10][10], int s, int dis[10])
{
  int v,count = 1,min,visited[10];
  for (int i = 1; i <= n; i++)
  {
    visited[i] = 0;
    dis[i] = cost[s][i];
  }
  visited[s] = 1;
  dis[s] = 0;
  while (count <= n){
    min = 999;
    for (int i=1; i<=n; i++)
    if (dis[i] < min && visited[i] == 0)
    {
        min = dis[i];
        v = i;
    }
    visited[v] = 1;
    count++;
    for (int i = 1; i <= n; i++)
      if (dis[i] > dis[v] + cost[v][i])
        dis[i] = dis[v] + cost[v][i];

  }
}
int main()
{
  int n, s, cost[10][10], dis[10];
  cout<<"\nEnter no. of nodes : ";
  cin>>n;
  cout<<"\nRead Cost Matrix :-\n";
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      cin>>cost[i][j];
      if (cost[i][j] == 0)
        cost[i][j] = INF;
    }
    cout<<"\nEnter Source Vertex : ";
    cin>>s;
    Dijkstras(n,cost,s,dis);
    cout<<"\n\nShortest path from "<<s<<" is :-\n";
    for (int i = 1; i <= n; i++)
      if (s != i)
        cout<<s<<" -> "<<i<<" = "<<dis[i]<<endl;
  return 0;
}
