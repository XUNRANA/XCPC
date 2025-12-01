#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	int x=0,y=0;
	while(n--)
	{
		char ch;
		int t;
		cin>>ch>>t;
		if(ch=='S') y-=t;
		else if(ch=='N') y+=t;
		else if(ch=='E') x+=t;
		else x-=t; 
	}
	
	if(!x&&!y)
	{
		cout<<"7 E\n";
		cout<<"Z 1\n";
		cout<<"L\n";
		cout<<"Z 1\n";
		cout<<"L\n";
		cout<<"Z 1\n";
		cout<<"L\n";
		cout<<"Z 1\n";
	}
	else if(!x)
	{
		if(y>0)
		{
			cout<<"1 N\n";
			cout<<"Z "<<y<<"\n";
		}
		else
		{
			cout<<"1 S\n";
			cout<<"Z "<<-y<<"\n";
		}
	}
	else if(!y)
	{
		if(x>0)
		{
			cout<<"1 E\n";
			cout<<"Z "<<x<<"\n";
		}
		else
		{
			cout<<"1 W\n";
			cout<<"Z "<<-x<<"\n";
		}
	}
	else
	{
		if(x>0&&y>0)
		{
			cout<<"3 E\n";
			cout<<"Z "<<x<<"\n";
			cout<<"L\n";
			cout<<"Z "<<y<<"\n";
		}
		if(x<0&&y>0)
		{
			cout<<"3 W\n";
			cout<<"Z "<<-x<<"\n";
			cout<<"R\n";
			cout<<"Z "<<y<<"\n";
		}
		if(x<0&&y<0)
		{
			cout<<"3 S\n";
			cout<<"Z "<<-y<<"\n";
			cout<<"R\n";
			cout<<"Z "<<-x<<"\n";
		}
		if(x>0&&y<0)
		{
			cout<<"3 S\n";
			cout<<"Z "<<-y<<"\n";
			cout<<"L\n";
			cout<<"Z "<<x<<"\n";
		}
	}
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
