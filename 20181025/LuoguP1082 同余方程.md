**[CODE]**

  #include<bits/stdc++.h>
	using namespace std;
	long long x,y;
	void ExGcd(long long a,long long b)
	{
		if(a==1&&b==0)
		{
			x=1;y=0;return;
		}
		ExGcd(b,a%b);
		long long k=x;
		x=y;
		y=k-(a/b)*y;
	}
	int main()
	{
		long long a,b;
		cin>>a>>b;
		ExGcd(a,b);
		cout<<((x%b)+b)%b<<endl;;
		return 0;
	}

**[解题报告]**

 EXGCD的板子，又打了一遍。
