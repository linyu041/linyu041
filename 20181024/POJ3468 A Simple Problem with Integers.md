**[CODE]**

	#include<iostream>
	#include<algorithm>
	#include<cstdio>
	#include<vector>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	#define D(i,j,k) for(int i=j;i>=k;--i)
	const int N=(1e5)+5;
	int n,a[N],m;
	long long tr[2][N];
	void Update1(int x,long long k)
	{
		for(;x<=n;x+=x&(-x))
		{
			tr[0][x]+=k;
		}	
	}
	void Update2(int x,long long k)
	{
		for(;x<=n;x+=x&(-x))		
		{
			tr[1][x]+=k;
		}
	}
	long long Query1(int x,long long sum=0)
	{
		for(int i=x;i>0;i-=i&(-i))	sum+=(x+1)*tr[0][i];
		return sum;
	}
	long long Query2(int x,long long sum=0)
	{
		for(int i=x;i>0;i-=i&(-i))	sum+=tr[1][i];
		return sum;
	}
	long long sum1[N];
	int main()
	{
		scanf("%d%d",&n,&m);
		U(i,1,n)
		{
			scanf("%d",&a[i]);
			sum1[i]=sum1[i-1]+a[i];
		}
		char c=getchar();int x,y;
		long long w;
		U(i,1,m)
		{
			while(!isalpha(c))	c=getchar();
			if(c=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%lld\n",(sum1[y]+Query1(y)-Query2(y))-(sum1[x-1]+Query1(x-1)-Query2(x-1)));
			}
			else
			{
				scanf("%d%d%lld",&x,&y,&w);
				Update1(x,w);Update1(y+1,-w);
				Update2(x,x*w);Update2(y+1,-(y+1)*(w));
			}
			c=getchar();
		}
		return 0;
	}
  
  **[解题报告]**
  
  用树状数组维护加法区间修改，区间查询的模板题。注意在读入时不能直接更新差分数组。
