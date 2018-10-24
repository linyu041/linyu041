**[CODE]**

	#include<algorithm>
	#include<cstdio>
	#include<iostream>
	#include<vector>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	#define D(i,j,k) for(int i=j;i>=k;--i)
	const int N=(1e5)+5;
	int l[N<<2],r[N<<2],sum[N<<2];
	int n,a[N],hei[N];
	void Build(int x,int L,int R)
	{
		l[x]=L;r[x]=R;
		if(L==R)
		{
			sum[x]=1;
			return;
		}
		int mid=(L+R)>>1;
		Build(x<<1,L,mid);Build(x<<1|1,mid+1,R);
		sum[x]=sum[x<<1]+sum[x<<1|1];
	}
	int Query(int x,int k)
	{
		if(k<0)	return 0;
		if(l[x]==r[x])	return l[x];
		if(sum[x<<1]>=k)	
		{
			return Query(x<<1,k);
		}
		else
		{
			return Query(x<<1|1,k-sum[x<<1]);
		}
	}
	void Update(int x,int y,int z)
	{
		if(l[x]==r[x]&&l[x]==y)
		{
			sum[x]+=z;
			return;
		}
		int mid=(l[x]+r[x])>>1;
		if(y<=mid)	Update(x<<1,y,z);
		else		Update(x<<1|1,y,z);
		sum[x]=sum[x<<1]+sum[x<<1|1];
	}
	int main()
	{
		scanf("%d",&n);
		U(i,2,n)	scanf("%d",&a[i]);
		Build(1,1,n);
		a[1]=0;
		D(i,n,1)
		{
			hei[i]=Query(1,a[i]+1);
			Update(1,hei[i],-1);
		}
		U(i,1,n)
		{
			printf("%d\n",hei[i]);
		}
		return 0;
	}
  
  **[解题报告]**
  初始时吧所有点设为1,,那么题目就是要我们找第a[i]+1个1在什么位置。直接在线段树上二分即可。
