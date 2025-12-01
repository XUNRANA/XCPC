#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[10000001];
vector<int>p;
void init()
{
	for(int i=2;i<=1e7;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e7;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int d=n/i;
        ans+=upper_bound(p.begin(),p.end(),d)-p.begin();
    }
    cout<<ans<<"\n";
    // 2 16
    // 6 10
    // 2*3 2*3*3
    // 30 2
    //15=3*5
}

signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
