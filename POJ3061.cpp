#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
#define U(i,j,k) for(int i=j;i<=k;++i)
#define D(i,j,k) for(int i=j;i>=k;--i)
const int N=2000005;
int n,a[N],sum[N],S;
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&S);
		U(i,1,n)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		int r=0,ans=INT_MAX,s=0;
		for(int l=1;l<=n;++l)
		{
			s-=sum[l-1];
			while(sum[r]-sum[l-1]<S&&r<n)	
			{
				++r;
				s+=sum[r];
			}
			if(sum[r]-sum[l-1]>=S)	ans=min(ans,r-l+1);
		}
		printf("%d\n",ans!=INT_MAX?ans:0);
	}
	return 0;
}
