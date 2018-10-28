**[CODE]**

[栈]

    #include<bits/stdc++.h>
    using namespace std;
    #define U(i,j,k) for(int i=j;i<=k;++i)
    const int N=1e6;
    int a[N],b[N],n,c[N];
    int sta[N],top;
    int main()
    {
      scanf("%d",&n);
      U(i,1,n)	scanf("%d",a+i);
      U(i,1,n)	scanf("%d",b+i);
      U(i,1,n)	c[a[i]]=i;
      U(i,1,n)	b[i]=c[b[i]];
      U(i,1,n)
      {
        if(b[i]>sta[top])
        {
          sta[++top]=b[i];
        }
        else
        {
          int t=lower_bound(sta+1,sta+1+top,b[i])-sta;
          if(t<=top&&sta[t]>b[i])	sta[t]=b[i];
        }
      }
      printf("%d\n",top);
      return 0;
    }
  
[树状数组]

    #include<bits/stdc++.h>
    using namespace std;
    #define U(i,j,k) for(int i=j;i<=k;++i)
    const int N=1e6;
    int a[N],b[N],n,c[N],tr[N],f[N];
    int Get(int x)
    {
      int sum=0;
      for(;x>0;x-=x&(-x))	sum=max(sum,tr[x]);
      return sum;
    }
    inline void Update(int x,int y)
    {
      for(;x<=n;x+=x&(-x))	tr[x]=max(tr[x],y);
    }
    int main()
    {
      scanf("%d",&n);
      U(i,1,n)	scanf("%d",a+i);
      U(i,1,n)	scanf("%d",b+i);
      U(i,1,n)	c[a[i]]=i;
      U(i,1,n)	b[i]=c[b[i]];
      int ans=0;
      U(i,1,n)
      {
        f[i]=Get(b[i])+1;
        Update(b[i],f[i]);
        ans=max(ans,f[i]);
      }
      printf("%d\n",ans);
      return 0;
    }
    
**[Solution]**

说是最长公共子序列模板题,其实到最后就是LIS模板.我们可以把第二个序列映射成对应数字在第一个序列中的位置,那么我们要找的就是一段最长不降子序列.接下来怎么做随意.
