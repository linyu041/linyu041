**[CODE]**

    #include<bits/stdc++.h>
    using namespace std;
    const int N=(1e5)+7,M=(250005);
    int a[N],n,m;
    struct Edge
    {
      int x,y;
    }e[M];
    int k[N],g[N];
    inline void Read(int &x)
    {
      char c=getchar();x=0;
      while(!isdigit(c))	c=getchar();
      while(isdigit(c))	x=(x<<1)+(x<<3)+c-'0',c=getchar();
    }
    vector<int> v[N];
    int main()
    {
      Read(n);Read(m);
      for(register int i=1;i<=n;++i)	Read(a[i]);
      int x,y;
      for(int i=1;i<=m;++i)
      {
        Read(e[i].x);Read(e[i].y);
        ++g[e[i].x];++g[e[i].y];
      }
      long long ans=0;
      int tmp;
      for(int i=1;i<=m;++i)
      {		
        if(g[e[i].x]>g[e[i].y]||(g[e[i].x]==g[e[i].y]&&e[i].x>e[i].y))
          swap(e[i].x,e[i].y);
        v[e[i].x].push_back(e[i].y);
      }
      for(int i=1;i<=m;++i)
      {
        tmp=max(a[e[i].x],a[e[i].y]);
        for(vector<int>::iterator it=v[e[i].x].begin();it!=v[e[i].x].end();++it)
          k[*it]=i;
        for(vector<int>::iterator it=v[e[i].y].begin();it!=v[e[i].y].end();++it)
          if(k[*it]==i)	ans+=max(a[*it],tmp);
      }
      printf("%lld\n",ans);
      return 0;
    }
    
**[Solution]**
这题告诉我们1不能用边链表存边,要用vector(#滑稽)另外这题按照编号从小的向大的建边有奇效.

正经一点,本题是找三元环的模板题,具体步骤:找到一条边,从度数小的那端枚举点,打个标记,再从另一边看能否匹配,能就更新答案.复杂度O(<img src="https://latex.codecogs.com/gif.latex?m\sqrt{m}" title="m\sqrt{m}" />)
