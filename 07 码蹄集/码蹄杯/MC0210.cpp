#include <bits/stdc++.h>
using namespace std;
#define int long long


int n;
vector<int> zfun(string s)//z算法，z[i]表示s[i...n]与s[1..n]的lcp 
{
	vector<int>z(s.size(),0);
	z[1]=n;
	for(int i=2,l=1,r=1;i<=n;i++)
	{
		z[i]=i<=r? min(z[i-l+1],r-i+1):0;
		while(i+z[i]<=n&&s[i+z[i]]==s[1+z[i]]) z[i]++;
		if(i+z[i]-1>r) r=i+z[i]-1,l=i;
	}
	return z;
}
int cnt[1000010];
void solve()
{
	string s;
	cin>>s;
	n=s.size();
	s="$"+s;
	vector<int>z=zfun(s);
	int ans=0;
	for(int i=2;i<s.size();i++)
	{
		if(i+z[i]==s.size())
		{
			if(cnt[z[i]]) ans=max(ans,z[i]);
		}
		cnt[z[i]]++;
	}

	// for(auto i:z) cout<<i<<" ";
	// cout<<"\n";
	
	if(ans) cout<<s.substr(1,ans)<<"\n";
	else cout<<"No\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
