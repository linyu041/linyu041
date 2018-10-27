**[CODE]**

    #include<bits/stdc++.h>
    using namespace std;
    #define U(i,j,k) for(int i=j;i<=k;++i)
    const int N=(1e6)+5;
    int n;
    struct Data
    {
      int x,y;	
    }a[N],b[N];
    int tota,totb;
    int cmp1(Data x,Data y)
    {
      return x.x!=y.x?x.x<y.x:x.y>y.y;
    }
    int cmp2(Data x,Data y)
    {
      return x.y!=y.y?x.y>y.y:x.x>y.x;
    }
    int main()
    {
      freopen("reformat.in","r",stdin);
      freopen("reformat.out","w",stdout);
      scanf("%d",&n);
      int x,y;
      U(i,1,n)
      {
        scanf("%d%d",&x,&y);
        if(x<=y)	a[++tota].x=x,a[tota].y=y;
        else		b[++totb].x=x,b[totb].y=y;
      }
      sort(a+1,a+1+tota,cmp1);
      sort(b+1,b+1+totb,cmp2);
      int need=0,ans=0,spar=0;
      for(int i=1;i<=tota;++i)
      {
        if(spar<a[i].x)
        {
          need=max(need,a[i].x-spar);
        }
        spar+=a[i].y-a[i].x;
      }
      for(int i=1;i<=totb;++i)
      {
        if(spar<a[i].x)
        {
          need=max(need,a[i].x-spar);	
        }
        spar-=a[i].y-a[i].x;
      }
      printf("%d\n",need);
      return 0;
    }
    
**[Solution]**

发现把格式化后变小的和格式化后变大的放在一起很难讨论,于是把他们分成两类:

1.格式化后变大的,按照所需要的空间大小从小到大格式化,空间不够用就申请新磁盘.
2.格式化后变小的,按照格式化后的空间大大小从大到小格式化,空间不够用就申请新的.在这里,剩余空间(spar)可以为负(反正多需要的空间都会在最后一个磁盘被算进答案
