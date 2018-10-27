**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	const int N=2000005,M=1000005;
	int a[N],n,m,cnt[M];
	int main()
	{
		scanf("%d%d",&n,&m);
		U(i,1,n)
		{
			scanf("%d",&a[i]);
		}
		cnt[a[0]]=1;
		int ans=INT_MAX,x=0,y=0,r=0,nwo=1;
		for(int l=1;l<=n;++l)
		{
			--cnt[a[l-1]];
			if(cnt[a[l-1]]==0)	--nwo;
			while(r<n&&nwo<m)
			{
				++r;
				if(!cnt[a[r]])	++nwo;
				++cnt[a[r]];
			}
			if(r-l+1<ans&&nwo==m)
			{
				ans=r-l+1;
				x=l;y=r;
			}
		}
		printf("%d %d\n",x,y);
		return 0;
	}

**[Solution]**

尺取法(在区间决策满足单调性的时候的一种做法)
