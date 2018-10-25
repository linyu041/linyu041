**[CODE]**

	#include<bits/stdc++.h>
	#include<algorithm>
	using namespace std;
	#define U(i,j,k) for(int i=j;i<=k;++i)
	int ans=0,n;
	int fr[55][55],a[55],sta[55],top;
	int Check(int x)
	{
		for(int i=1;i<=top;++i)	if(fr[x][sta[i]]==0)	return 0;
		return 1;
	}
	int main()
	{
		scanf("%d",&n);
		int x,y;
		srand(time(NULL));
		while(scanf("%d%d",&x,&y)!=EOF)
		{
			fr[x][y]=fr[y][x]=1;
		}
		U(i,1,n)	a[i]=i;
		U(i,1,10000)
		{
			U(j,1,n)	a[j]=j;
			U(j,1,n)
			{
				x=rand()%n+1;y=rand()%n+1;
				swap(a[x],a[y]);
			}
			U(j,1,n)
			{
				if(Check(a[j]))	sta[++top]=a[j];
			}
			ans=max(ans,top);
			top=0;
		}
		printf("%d\n",ans);
		return 0;
	}
  
  **[解题报告]**
  乱搞= =.随机一个序列，从前往后选尽量多的人。
