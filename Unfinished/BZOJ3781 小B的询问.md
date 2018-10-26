**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	const int SIZE=226,N=50005;
	int a[N],n,m,k;
	int cnt[N];
	struct Ask
	{
		int l,r,bl,id;
	}b[N];
	long long res[N];
	int cmp(Ask x,Ask y)
	{
		return x.bl!=y.bl?x.bl<y.bl:x.r<y.r;
	}
	void Solve()
	{
		int l=1,r=0;
		long long ans=0;
		for(int i=1;i<=m;++i)
		{
			while(l<b[i].l)	--cnt[a[l]],ans-=cnt[a[l]]*2+1,++l;
			while(r<b[i].r)	++r,++cnt[a[r]],ans+=cnt[a[r]]*2-1;
			while(l>b[i].l)	--l,++cnt[a[l]],ans+=cnt[a[l]]*2-1;
			while(r>b[i].r)	--cnt[a[r]],ans-=cnt[a[r]]*2+1,--r;
			res[b[i].id]=ans;
		}
		U(i,1,m)
		{
			printf("%d\n",res[i]);
		}
	}
	int main()
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		U(i,1,m)
		{
			scanf("%d%d",&b[i].l,&b[i].r);
			b[i].id=i;
			b[i].bl=(b[i].l-1)/SIZE+1;
		}
		sort(b+1,b+1+m,cmp);
		Solve();
		return 0;
	}
	
**[Solution]**

裸莫队.
