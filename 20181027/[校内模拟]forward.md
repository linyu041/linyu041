**[CODE]**

    #include<bits/stdc++.h>
    using namespace std;
    #define U(i,j,k) for(int i=j;i<=k;++i)
    #define D(i,j,k) for(int i=j;i>=k;--i)
    const int N=50005;
    int n,m,sta[N],inque[N],top,que[N],nwo,now;
    inline void Solve()
    {
      ++now;
      scanf("%d%d",&n,&m);
      int x;
      U(i,1,m)
      {
        scanf("%d",&x);
        sta[++top]=x;
      }
      D(i,top,1)
      {
        if(inque[sta[i]]!=now)
        {
          inque[sta[i]]=now;
          que[++nwo]=sta[i];
        }
      }
      U(i,1,n)
      {
        if(inque[i]!=now)	que[++nwo]=i;
      }
      printf("%d",que[1]);
      U(i,2,nwo)	printf(" %d",que[i]);
      putchar('\n');
    }
    int main()
    {
      freopen("forward.in","r",stdin);
      freopen("forward.out","w",stdout);

      int T;
      scanf("%d",&T);
      while(T--)
      {
        nwo=top=0;
        Solve();
      }
      return 0;
    }
    
**[Solution]**

学傻了2333.用栈实现了倒序扫描的操作23333.

正经解法:倒序扫描操作序列,按照顺序把第一次出现的数字接到答案序列末端,最后把没放进去的数字放入答案序列,输出.
