#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <cstdio>
using namespace std;
const int maxn=1e4+10;

int times, cont;
bool f[maxn], gg[maxn];
int low[maxn], dfn[maxn], scc[maxn];

stack<int> q;
vector<int> g[maxn];

void Tarjan(int u){
	low[u] = dfn[u] = ++times;
	q.push(u);
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v=g[u][i];
		if (!dfn[v]){                           //没有搜索过就入栈搜索
			Tarjan(v);
			low[u]=min(low[u], low[v]);         //子节点的low值和当前low值取最小
		}
		else if ( !scc[v] ) low[u]=min(low[u], dfn[v]);  //如果还在栈中就更新low值
	}
	if (low[u] == dfn[u])           //当前节点就是根节点就把这个点之后进栈的点都出栈
	{
		cont ++;
		while (true){
			int v= q.top();
			q.pop();
			scc[v] = cont;
			if (v == u) break;
		}
	}
	return;
}
