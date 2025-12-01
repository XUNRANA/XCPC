#include <bits/stdc++.h>
using namespace std;
int c[]={13,1,2,3,5,4,4,2,2,2};
int t[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int f(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x%10];
		x/=10;
	}
	return res;
}
int is(int x)
{
	return x%4==0;
}
void solve()
{
	int a=0;
	for(int y=2000;y<=2023;y++)
	{
		for(int m=1;m<=12;m++)
		{
			for(int d=1;d<=t[m];d++)
			{
				int cnt=f(y*10000+m*100+d);
//				cout<<y*10000+m*100+d<<"\n";
				if(cnt>50) a++;
			}	
			if(m==2&&is(y))
			{
				int cnt=f(y*10000+m*100+29);
//				cout<<y*10000+m*100+d<<"\n";
				if(cnt>50) a++;
			}
		}
	}
	
	for(int y=2024;y<=2024;y++)
	{
		for(int m=1;m<=4;m++)
		{
			for(int d=1;d<=t[m];d++)
			{
				
				int cnt=f(y*10000+m*100+d);
//				cout<<y*10000+m*100+d<<"\n";
				if(cnt>50) a++;
				if(m==4&&d==13) break;
			}	
			if(m==2&&is(y)) 
			{
				int cnt=f(y*10000+m*100+29);
//				cout<<y*10000+m*100+d<<"\n";
				if(cnt>50) a++;
			}
		}
	}
	
	cout<<a<<"\n";
	//3228
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
