**[CODE]**

    #include<bits/stdc++.h>
    using namespace std;
    #define U(i,j,k) for(register int i=j;i<=k;++i)
    typedef long long ll;
    long long p,q,ans;
    ll GCD(ll x,ll y)
    {
      ll r=x%y;
      while(r!=0)
      {
        x=y;y=r;r=x%y;
      }
      return y;
    }
    int main()
    {
      freopen("simplecalc.in","r",stdin);
      freopen("simplecalc.out","w",stdout);
      int T;
      scanf("%d",&T);
      while(T--)
      {
        ans=0;
        scanf("%lld%lld",&p,&q);
        ll k=GCD(p,q);
        ans=(p+1)*q-p+k;
        printf("%lld\n",ans/2);
      }
      return 0;
    }
    
**[Solution]**

数学题...把原先的那个式子×2,再化简可得结论,ans=(p+1)q-p+GCD(p,q).
