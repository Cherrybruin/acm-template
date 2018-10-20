#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
const int maxv=1100,maxn=1100;  //边的条数和点的个数

struct node
{
	int dis,num;
	bool operator<(const node b) const{
		return dis>b.dis;
	}
};

int d[maxn],nex[maxv],frist[maxn],u[maxv],v[maxv],w[maxv];

int main()
{
	int n,m,s,t;
	scanf("%d%d%d%d", &n,&m,&s,&t);

	memset(frist,0,sizeof(frist));
	for (int e=1; e<=m; e++)
	{
		scanf("%d%d%d",&u[e],&v[e],&w[e]);
		nex[e]=frist[u[e]];
		frist[u[e]]=e;
		u[e+m]=v[e]; v[e+m]=u[e]; w[e+m]=w[e];
		nex[e+m]=frist[u[e+m]];
		frist[u[e+m]]=e+m;
	}

	priority_queue<node> q;
	node a;
	a.dis=0; a.num=s;
	q.push(a);
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	while (!q.empty())
	{
		node e=q.top();
		q.pop();
		if (e.dis!=d[e.num]) continue;
		int p=frist[e.num];
		int x=e.num;
		while (p!=0)
		{
			int y=v[p];
			if (d[y]>d[x]+w[p]){
				d[y]=d[x]+w[p];
				node aa;
				aa.dis=d[y];
				aa.num=y;
				q.push(aa);
			}
			p=nex[p];
		}
	}
	printf("%d\n",d[t]);
	
	return 0;
}
/*
4 4 1 4
1 2 2
1 3 3 
2 4 4 
3 4 5
*/