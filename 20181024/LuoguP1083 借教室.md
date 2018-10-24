**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	const int N=(1e6+5);
	struct Data
	{
		int d,l,r;
	}a[N];
	int n,m,res[N],ans,need[N];
	int Check(int x)
	{
		memset(need,0,sizeof(need));
		for(int i=1;i<=x;++i)
		{
			need[a[i].l]+=a[i].d;
			need[a[i].r+1]-=a[i].d;
		}
		for(int i=1;i<=n;++i)
		{
			need[i]+=need[i-1];
			if(need[i]>res[i])
			{
				return 0;
			}	
		}
		return 1;
	}
	int main()
	{
		scanf("%d%d",&n,&m);
		U(i,1,n)	scanf("%d",&res[i]);
		U(i,1,m)
		{
			scanf("%d%d%d",&a[i].d,&a[i].l,&a[i].r);
		}
		int l=1,r=m;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(Check(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else	r=mid-1;
		}
		if(ans==m)	printf("%d\n",0);
		else		printf("%d\n%d\n",-1,ans+1);
		return 0;
	}
**[解题报告]**

二分能完成的订单数量。差分数组维护所需要的教室数量，每次O(n)检查。
