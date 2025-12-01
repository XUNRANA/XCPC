#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(min(c,d)<a&&max(c,d)>=b)
	{
		cout<<c<<"-Y "<<d<<"-Y\n";
		if(c<d) cout<<"qing 2 zhao gu hao 1\n";
		else cout<<"qing 1 zhao gu hao 2\n";
	}
	else if(min(c,d)>=a)
	{
		cout<<c<<"-Y "<<d<<"-Y\n";
		cout<<"huan ying ru guan\n";
	}
	else if(max(c,d)<a)
	{
		cout<<c<<"-N "<<d<<"-N\n";
		cout<<"zhang da zai lai ba\n";
	}
	else if(max(c,d)>=a&&min(c,d)<a)
	{
		if(c>d) 
		{
			cout<<c<<"-Y "<<d<<"-N\n";
			cout<<"1: huan ying ru guan\n";
		}
		else 
		{
			cout<<c<<"-N "<<d<<"-Y\n";
			cout<<"2: huan ying ru guan\n";
		}
	
		
	}
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

