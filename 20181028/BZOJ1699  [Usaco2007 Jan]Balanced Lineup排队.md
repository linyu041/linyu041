**[CODE]**

    #include<bits/stdc++.h>
    const int N=(5e5)+5;
    using namespace std;
    int n,tag;
    inline void Read(int &x)
    {
      char c=getchar();x=tag=0;
      for(;!isdigit(c)&&c!='-';c=getchar());
      for(;c=='-';tag=1,c=getchar());
      for(;isdigit(c);x=(x<<1)+(x<<3)+c-'0',c=getchar());
      x=tag?-x:x;
    };
    struct SegTree
    {
      int maxx[N<<2],minn[N<<2],l[N<<2],r[N<<2];
      void Build(int x,int L,int R)
      {
        l[x]=L;r[x]=R;
        if(L==R)
        {
          Read(maxx[x]);
          minn[x]=maxx[x];
          return;
        }
        int mid=(L+R)>>1;
        Build(x<<1,L,mid);Build(x<<1|1,mid+1,R);
        maxx[x]=max(maxx[x<<1],maxx[x<<1|1]);
        minn[x]=min(minn[x<<1],minn[x<<1|1]);
      };
      int Query_Min(int x,int L,int R)
      {
        if(l[x]>R||r[x]<L)	return INT_MAX;
        if(L<=l[x]&&r[x]<=R)
        {
          return minn[x];
        }
        return min(Query_Min(x<<1,L,R),Query_Min(x<<1|1,L,R));
      };
      int Query_Max(int x,int L,int R)
      {
        if(l[x]>R||r[x]<L)	return -INT_MAX;
        if(L<=l[x]&&r[x]<=R)
        {
          return maxx[x];
        };
        return max(Query_Max(x<<1,L,R),Query_Max(x<<1|1,L,R));
      };
    }T;
    int q;
    int main()
    {
      Read(n);Read(q);
      T.Build(1,1,n);
      int x,y;
      for(int i=1;i<=q;++i) 
      {
        Read(x);Read(y);
        printf("%d\n",T.Query_Max(1,x,y)-T.Query_Min(1,x,y));
      }
      return 0;
    }
    
**[Solution]**

线段树裸题.
