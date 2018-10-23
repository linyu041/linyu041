#include<bits/stdc++.h>
using namespace std;
#define U(i,j,k) for(int i=j;i<=k;++i)
const int N=5e4+5;
int d[N],fa[N],n,m,ans;
int Find(int x)
{
	if(fa[x]==x)	return x;
	int fx=Find(fa[x]);
	d[x]=(d[x]+d[fa[x]])%3;
	return fa[x]=fx;
}
void Subtask1(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx==fy)
	{
		if(d[x]!=d[y])	++ans;
		return;
	}
	d[fx]=(d[y]-d[x]+3)%3;
	fa[fx]=fy;
}
void Subtask2(int x,int y)//y被x吃 
{
	int fx=Find(x),fy=Find(y);
	if(fx==fy)
	{
		if((d[y]+1)%3!=d[x])++ans;
		return;
	}
	d[fx]=(d[y]-d[x]+4)%3;
	fa[fx]=fy;
}
int main()
{
	scanf("%d%d",&n,&m);
	U(i,1,n)	fa[i]=i;
	int opt,x,y;
	U(i,1,m)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(x>n||y>n)		{++ans;continue;}
		if(opt==2&&x==y)	{++ans;continue;}
		if(opt==1)
		{
			Subtask1(x,y);
		}
		else
		{
			Subtask2(x,y);
		}
	}
	printf("%d\n",ans);
	return 0;
}


![image]https://github.com/linyu041/linyu041/blob/master/image/%E9%A3%9F%E7%89%A9%E9%93%BE.png
