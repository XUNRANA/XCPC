#include <bits/stdc++.h>
using namespace std;
bool f[5000010];
vector<int>p;
void init()
{
	for(int i=2;i<=5e6;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&i*p[j]<=5e6;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int fx[5000010];
void solve()
{
	int n;
	cin>>n;
	for(auto i:p)
	{
		if(i>n) break;
		for(int j=i;j<=n;j+=i) fx[j]++;
	}
    
	int ans=0;
	for(int i=2;i<=n;i++) if(fx[i]>=2) ans++;
	cout<<ans<<"\n";
}

int main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
