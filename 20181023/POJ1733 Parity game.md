**[CODE]**

	#include<iostream>
	#include<algorithm>
	#include<cstdio>
	#include<vector>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	const int N=10005;
	struct Data
	{
		int l,r,tag;
	}a[N];
	int b[N],tot,n,m,fa[N<<1];
	char s[11];
	int Rank(int x)
	{
		return lower_bound(b+1,b+1+m,x)-b+1;
	}
	int Find(int x)
	{
		return fa[x]!=x?fa[x]=Find(fa[x]):x;
	}
	int main()
	{
		scanf("%d%d\n",&m,&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %s\n",&a[i].l,&a[i].r,s);
			if(s[0]=='e')	a[i].tag=0;
			else			a[i].tag=1;
			b[++tot]=a[i].l;b[++tot]=a[i].r;
		}
		sort(b+1,b+1+tot);
		m=unique(b+1,b+1+tot)-b-1;
		U(i,1,m+m+2)	fa[i]=i;
		for(int i=1;i<=n;++i)
		{
			int l_odd=Rank(a[i].l-1),l_even=Rank(a[i].l-1)+m,r_odd=Rank(a[i].r),r_even=Rank(a[i].r)+m;
			if(a[i].tag==0)
			{
				if(Find(l_odd)==Find(r_even))
				{
					printf("%d\n",i-1);
					return 0;
				}
				fa[Find(l_odd)]=Find(r_odd);
				fa[Find(l_even)]=Find(r_even);
			}
			else
			{
				if(Find(l_odd)==Find(r_odd))
				{
					printf("%d\n",i-1);
					return 0;
				}
				fa[Find(l_odd)]=Find(r_even);
				fa[Find(l_even)]=Find(r_odd);
			}
		}
		printf("%d\n",n);
		return 0;
	}
	
 **[解题报告]**
 根据题意，可以得出sum[l-1],sum[r]的奇偶性关系，把他们拆成两个点 ，分别代表奇数和偶数，并查集维护。
