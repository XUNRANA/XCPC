#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int a,b,c;
void solve()
{
	cin>>a>>b>>c;
	int mx=max({a,b,c});
	int mi=min({a,b,c});
	if(mx==mi)
	{
		if(!mx) cout<<"YES\n1 1 1\n";
		else cout<<"NO\n";
		return ;
	}
	
	if(!a&&b==c)
	{
		
		cout<<"YES\n";
		cout<<2*b<<" "<<b<<" "<<3*b<<"\n";
		return ;
	}
	
	if(!b&&a==c)
	{
		cout<<"YES\n";
		cout<<3*a<<" "<<2*a<<" "<<a<<"\n";
		return ;
	}
	
	if(!c&&a==b)
	{
		cout<<"YES\n";
		cout<<a<<" "<<3*a<<" "<<2*a<<"\n";
		return ;
	}
	
	if(!a&&!b)
	{
		cout<<"YES\n";
		cout<<2*c<<" "<<2*c<<" "<<c<<"\n";
		return ;
	}
	
	if(!b&&!c)
	{
		cout<<"YES\n";
		cout<<a<<" "<<2*a<<" "<<2*a<<"\n";
		return ;
	}
	
	if(!a&&!c)
	{
		cout<<"YES\n";
		cout<<2*b<<" "<<b<<" "<<2*b<<"\n";
		return ;
	}
	
	
	if(a<b&&b==mx)
	{
		cout<<"YES\n";
		cout<<a+b<<" "<<b<<" "<<a+b+c<<"\n";
		return ;
	}
	if(b<c&&c==mx)
	{
		cout<<"YES\n";
		cout<<a+b+c<<" "<<b+c<<" "<<c<<"\n";
		return ;
	}
	if(c<a&&a==mx)
	{
		cout<<"YES\n";
		cout<<a<<" "<<a+b+c<<" "<<a+c<<"\n";
		return ;
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
