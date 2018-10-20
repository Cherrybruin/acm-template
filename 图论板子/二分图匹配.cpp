#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector <int> q,G[5000]; 
int n,match[5000];
bool used[5000];

void addedge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v)
{
	used[v]=true;
	
	for (int i=0; i<G[v].size(); i++)
	{
		int u=G[v][i];
			
		if ( match[u]==-1 || !used[match[u]] && dfs(match[u]) )
		{
			match[v]=u;
			match[u]=v;
			return true;		
		}
	}
	
	return false;
}