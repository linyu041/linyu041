**[CODE]**

	#include<bits/stdc++.h>
	using namespace std;
	int T,rel,top,flag;
	char s[500005];
	vector<int> v;
	pair<int,int> sta[500005],sta1[500005];
	void Solve2()
	{
		int tag=0;
		for(int i=1;i<v.size()-1;++i)
		{
			tag=1;
			if(v[i]!=v[1])
			{
				tag=-1;break;
			}
		}
		if(tag==1&&rel==1)
		{
			flag=1;
			printf("empty\n");return;
		}
		if(rel%10==1)//< <=
		{
			for(vector<int>::iterator i=v.begin()+2;i<v.end();i+=2)
			{
				sta[++top]=make_pair(*(i-1),*i);
			}
		}
		else//> >=
		{
			for(vector<int>::iterator i=v.begin()+1;i<v.end();i+=2)
			{
				sta[++top]=make_pair(*(i-1),*i);
			}
		}
	}
	void Solve1()
	{
		if(rel%10==1) //< <=
		{
			for(vector<int>::iterator i=v.begin()+1;i<v.end();i+=2)
			{
				sta[++top]=make_pair(*(i-1),*i);
			}
		}
		else		//> >=
		{
			for(vector<int>::iterator i=v.begin()+2;i<v.end();i+=2)
			{
				sta[++top]=make_pair(*(i-1),*i);
			}
		}
	}
	void Solve(int x)
	{
		flag=0;
		if(x&1)		Solve1();
		else		Solve2();
		if(flag==1)	return;
		int head=0;
		for(int i=1;i<=top;++i)
		{
			if(rel>10)
			{
				if(i+1<=top&&sta[i+1].first==sta[i].second)
				{
					sta[i+1].first=sta[i].first;
				}
				else	sta1[++head]=sta[i];			
			}
			else		
			{
				if(sta[i].first!=sta[i].second)	sta1[++head]=sta[i];
			}
		}
		if(head==0)	printf("empty");
		for(int i=1;i<=head;++i)	
		{
			if(rel<10||sta1[i].first==-INT_MAX)	putchar('(');
			else								putchar('[');
			if(sta1[i].first==-INT_MAX)			printf("-inf,");
			else								printf("%d,",sta1[i].first);
			if(sta1[i].second==INT_MAX)			printf("+inf");
			else								printf("%d",sta1[i].second);
			if(rel<10||sta1[i].second==INT_MAX)	putchar(')');
			else								putchar(']');
			if(i!=head)					putchar(',');
		}
		putchar('\n');
	}
	int main()
	{
		freopen("inequality.in","r",stdin);
		freopen("inequality.out","w",stdout);
		
		scanf("%d\n",&T);
		while(T--)
		{
			scanf("%s\n",s);
			int len=strlen(s);
			int i=0,x,tag,cishu=0;top=0;flag=1;
			v.clear();
			while(i<len)
			{
				if(s[i]!='(')	break;
				++cishu;
				++i;x=0;tag=0;
				while(islower(s[i]))	++i;
				if(s[i]=='+')	tag=1;
				++i;
	 			while(isdigit(s[i]))
				{
					x=(x<<1)+(x<<3)+s[i]-'0';
					++i;
				}
				if(tag)	x=-x;
				v.push_back(x);
				if(s[i]==')')	++i;
			}
			v.push_back(INT_MAX);v.push_back(-INT_MAX);
			sort(v.begin(),v.end());
			rel=0;
			if(s[i]=='<')	rel=1;
			else			rel=2;
			if(s[i+1]=='=')	rel=rel*11;
			if(cishu==1)
			{
				if(rel<10)
				{
					if(rel==1)	printf("(-inf,%d)\n",v[1]);
					else		printf("(%d,+inf)\n",v[1]);
				}
				else
				{
					if(rel==11)	printf("(-inf,%d]\n",v[1]);
					else		printf("[%d,+inf)\n",v[1]);
				}
				continue;
			}
			Solve(cishu);
		}
		return 0;
	}
  
 **[解题报告]**
  
  数学题= =.序轴标根,穿针引线,合并区间
