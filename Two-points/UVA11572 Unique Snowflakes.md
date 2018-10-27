#include<bits/stdc++.h>
using namespace std;
#define U(i,j,k) for(int i=j;i<=k;++i)
#define D(i,j,k) for(int i=j;i>=k;--i)
const int N=(1e6)+5;
int tot,a[N],cnt[N],n,b[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		U(i,1,n)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		tot=unique(b+1,b+1+n)-b-1;
		U(i,1,n)	a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
		memset(cnt,0,sizeof(cnt));
		cnt[0]=1;
		int ans=0,r=0;
		for(int l=1;l<=n;++l)
		{
			--cnt[a[l-1]];
			while(r<n&&cnt[a[r+1]]==0)	++r,++cnt[a[r]];
			ans=max(ans,r-l+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
