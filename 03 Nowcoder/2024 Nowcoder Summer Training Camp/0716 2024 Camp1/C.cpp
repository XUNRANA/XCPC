#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p 1000000007
int q,t,v,ans;
void solve()
{
	cin>>q;
	vector<int>a;
	while(q--)
	{
		cin>>t>>v;
		while(t--)
		{
			ans-=a.size()*a.back()%p;
			ans=(ans+p)%p;
			a.pop_back();
		}
		a.push_back(v);
		ans+=v*a.size()%p;
		ans%=p;
		cout<<ans<<"\n";
	}
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}
