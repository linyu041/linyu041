**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	#define D(i,j,k) for(int i=j;i>=k;--i)
	const int N=1005;
	int vis[N],nwo;
	int n;
	struct Hole
	{
		long long x,y,z;
	}a[N];
	long long h,r;
	int tag;
	double Dist(int x,int y)
	{
		return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y)+(a[x].z-a[y].z)*(a[x].z-a[y].z));
	}
	void DDFS(int x)
	{
		if(tag)	return;
		if(a[x].z+r>=h)	
		{
			tag=1;
			return;
		}
		for(int i=1;i<=n;++i)
		{
			if(vis[i]!=nwo&&Dist(x,i)<=(double)r+r)
			{
				vis[i]=nwo;
				DDFS(i);
			}
		}
	}
	int main()
	{
		int T;
		scanf("%d",&T);
		while(T--)
		{
			scanf("%d%lld%lld",&n,&h,&r);
			U(i,1,n)
				scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			++nwo;tag=0;
			for(int i=1;i<=n;++i)
			{
				if(a[i].z-r<=0&&vis[i]!=nwo)
				{
					vis[i]=nwo;
					DDFS(i);
				}
				if(tag)	break;
			}
			if(tag)	printf("Yes\n");
			else	printf("No\n");
		}
		return 0;
	}
  
**[解题报告]**

暴力O(n^2)搜索即可。
