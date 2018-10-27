#include<bits/stdc++.h>
using namespace std;
#define U(i,j,k) for(int i=j;i<=k;++i)
const int N=(2e5)+5;
int n,tr[N];
long long t,a[N],sum[N],b[N];
void Update(int x,int y)
{
	for(;x<=n;x+=x&(-x))	tr[x]+=y;
}
long long Get(int x,long long sum=0)
{
	for(;x>0;x-=x&(-x))		sum+=tr[x];
	return sum;
}
long long ans=0;
int main()
{
	scanf("%d%I64d",&n,&t);
	U(i,1,n)
	{
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		b[i]=sum[i];
	}
	sort(b+1,b+1+n+1);
	int tot=unique(b+1,b+1+n+1)-b-1;
	Update(lower_bound(b+1,b+1+tot,sum[0]-t)-b,1);
	for(int i=1;i<=n;++i)
	{
		int tp=lower_bound(b+1,b+1+tot,sum[i]-t)-b;
		int tnwo=lower_bound(b+1,b+1+tot,sum[i])-b;
		if(tp!=sum[i]-t)	--tp;
		ans+=i-Get(tp);
		Update(tnwo,1);
	}
	printf("%I64d\n",ans);
	return 0;
}
