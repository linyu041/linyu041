**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	const int N=1005;
	int n,num;
	int fa[N],siz[N],d[N];
	int Find(int x)
	{
		if(fa[x]==x)	return x;
		int fx=Find(fa[x]);
		d[x]+=d[fa[x]];
		return fa[x]=fx;
	}
	void Merge(int x,int y)
	{
		if(y==0)	return;
		int fx=Find(x),fy=Find(y);
		siz[fy]+=siz[fx];
		siz[fx]=0;
		d[fx]=d[y]+1-d[x];
		fa[fx]=fy;
	}
	vector<int> ans,v;
	int vis[N],limt;
	bitset<N+N> f;
	int main()
	{
		freopen("queue.in","r",stdin);
		freopen("queue.out","w",stdout);
		
		scanf("%d%d",&n,&num);
		U(i,1,n)	fa[i]=i,siz[i]=1;
		int x;
		U(i,1,n)
		{
			scanf("%d",&x);
			Merge(i,x);
		}
		v.push_back(Find(num));vis[Find(num)]=1;
		for(int i=1;i<=n;++i)
		{
			if(!vis[Find(i)])	
			{
				vis[Find(i)]=1;
				v.push_back(Find(i));
			}
		}
		f[0]=1;
		for(vector<int>::iterator i=v.begin()+1;i<v.end();++i)
		{
			f=f|(f<<siz[*i]);
		}
		for(int i=0;i<=n;++i)
		{
			if(i+d[num]+1>n)	break;
			if(f[i]==1)	
			{
				printf("%d\n",i+d[num]+1);
			}
		}
		return 0;
	}
  **[解题报告]**
  
  用bitset维护子集和，带权并查集维护每一个小队列里的信息即可。
