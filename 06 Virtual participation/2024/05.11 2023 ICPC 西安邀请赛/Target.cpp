#include <bits/stdc++.h>
using namespace std;
double a,b,b1,d;
int c;
int main()
{
	cin>>a>>b;
	if(b==0)
	{
		for(int i=1;i<=50;i++) cout<<"1";
		cout<<"\n";
		return 0;
	}
	while(1)
	{
		vector<int>f(60,0);
		c++;
		a*=0.5;
		if(a>b) continue;
		b1=b-a;
		d=0.5;
		for(int i=1;i<=c;i++)
		{
			if(b1>=d) 
			{
				b1-=d;
				f[i]=1;
			}
			d*=0.5;
		}
		if(b1<=0.0001)
		{
			string ans;
			for(int i=1;i<=c;i++)
			{
				if(f[i]) ans='2'+ans;
				else ans='1'+ans;
			}
			cout<<ans<<"\n";
			return 0;
		}
	}
}
