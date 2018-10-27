**[CODE]**

  #include<bits/stdc++.h>
  using namespace std;
  const int N=1000005;
  int a[N],n,f[N],maxx,ans[N];
  vector<int> p;
  int main()
  {
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
      scanf("%d",&a[i]);
      maxx=max(maxx,a[i]);
      ++f[a[i]];
    }
  
    for(int i=1;i<=maxx;++i)
    {
      if(f[i]!=0)
        for(int j=i;j<=maxx;j+=i)
        {
          ans[j]+=f[i];
        }
    }

    for(int i=1;i<=n;++i)
    {
      printf("%d\n",ans[a[i]]-1);
    }
    return 0;
  }

**[Solution]**

首先O(\[n^2\])的暴力很简单,不再赘述.但显然这在n<=1e5的条件下是过不了的,所以我们用一种类似与筛法的东西优化暴力.

发现一个数字k只会被它的约数更新,那么我们就枚举每一个出现过的数字,更新他们的倍数的答案.这样听起来时间复杂度很大,但其实是能过的.

仔细分析,设m=max{a[i]},则时间复杂度为:O(\[\sum_{i}^{n}b[i]\]),这里b[i]表示出现过的数字,可以发现,它是<=O(mlogm)的,这样我们就过了这道题.
