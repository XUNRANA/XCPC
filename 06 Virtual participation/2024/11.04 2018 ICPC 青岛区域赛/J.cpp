#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,x;
void solve()
{
	cin>>n>>m;
	vector<int>a;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(!x) cnt++;
		else a.push_back(x);
	}
	
	if(cnt>m) cout<<"Impossible\n";
	else if(m==n) cout<<"Richman\n";
	else
	{
		int ans=0;
		int f=0,mx=1e9;
		for(auto i:a)
		{
			if(cnt==m) f=1;
			
			if(!f)
			{
				ans+=i;
				cnt++;
			}
			else mx=min(mx,i);
		}
		cout<<ans+mx-1<<"\n";
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
