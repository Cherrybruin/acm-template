#include <iostream>
#include <set>
using namespace std;
typedef unsigned long long ull;
const ull b1=9997, b2=1000007;

char s[1005], h[100];
ull a[1005][1005], b[1005][1005], tmp[1005][1005], ha[1005][1005];
int n, m, t, p, q;
multiset<ull> unseen;

void cal(ull a[1005][1005], int n, int m)
{
	ull e=0;
	ull t1=1;
	for (int j=0; j<q; j++) t1*=b1;

	for (int i = 0; i < n; i++)
	{
		ull e=0;
		for (int j = 0; j < q; j++) e=e*b1+a[i][j];

		for (int j = 0; j+q <= m; j++)
		{
			tmp[i][j]=e;
			if (j+q<m) e=e*b1-t1*a[i][j]+a[i][j+q];
		}
	}
	ull t2=1;
	for (int i = 0; i < p; i++) t2 *= b2;

	for (int j = 0; j+q <= m; j++){
		ull e=0;
		for (int i = 0; i < p; i++) e=e*b2+tmp[i][j];

		for (int i = 0; i+p <= n; i++){
			ha[i][j]=e;
			if (i+p<n) e=e*b2-t2*tmp[i][j]+tmp[i+p][j];
		}
	} 
}

int main()
{
	int u=0;
	while (scanf("%d%d%d%d%d", &n, &m, &t, &p, &q)!=EOF)
	{
		if (!n && !m && !t && !p && !q) break;
		u++;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &s);
			for (int j = 0; j < m; j++)
				{
					a[i][j]=s[j];
				}
		}
		unseen.clear();
		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < p; j++)
			{
				scanf("%s", &h);
				for (int k = 0; k < q; k++)
				{
					b[j][k]=h[k];
				}
			}
			cal(b, p, q);
			unseen.insert(ha[0][0]);
		}
		cal(a, n, m);
		for (int i = 0; i+p <= n; i++)
		{
			for (int j = 0; j+q <= m; j++)
			{
				unseen.erase(ha[i][j]);
			}
		}
		int ans=t-unseen.size();
		printf("Case %d: %d\n",u, ans);
	}

	return 0;
}