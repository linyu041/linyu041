**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	#define D(i,j,k) for(int i=j;i>=k;--i)
	const int N=505;
	int n,m;
	long long f[N][N];
	int v[N],a[N],nxt[N],la[N],tot,g[N];
	inline void AddE(int x,int y)
	{
		v[++tot]=y;nxt[tot]=la[x];la[x]=tot;
	}
	queue<int> q;
	int siz[N];
	void DDFS(int x)
	{
		f[x][1]=a[x];
		for(int i=la[x];i;i=nxt[i])
		{
			DDFS(v[i]);
			for(int j=m+1;j>=0;--j)//01背包 
			{
				for(int k=1;k<j;++k)
				{
					f[x][j]=max(f[x][j],f[x][k]+f[v[i]][j-k]);
	//				cout<<x<<" "<<j<<" "<<k<<" "<<f[x][j]<<endl;
				}
			}
		}
	}
	int main()
	{
		scanf("%d%d",&n,&m);
		int x;
		U(i,1,n)
		{
			scanf("%d%d",&x,&a[i]);
			AddE(x,i);++g[x];
		}
		DDFS(0);
		cout<<f[0][m+1]<<endl;
		return 0;
	}
  
  **[解题报告]**
  
  用f[i][j]表示i点必选的情况下的最大学分.显然f[i][j]=max{f[son[i]][j-k]+f[i][k]}(1<=k<j)，DFS即可。注意01背包的转移。
