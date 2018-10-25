**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	int Q;
	unsigned long long l,r,sum;
	int main()
	{
		cin>>Q;
		while(cin>>l>>r)
		{
			unsigned long long x=l+r,y=r-l+1;
			sum=(x%9)*(y%9)*5;
			cout<<(sum+9)%9<<endl;
		}
		return 0;
	}
  
**[解题报告]**

水题。。ans=(l+r)*(r-l+1)%9，太大会爆 long long ，乘个2在mod 9意义下的逆元.
