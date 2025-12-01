#include <bits/stdc++.h>
using namespace std;
#define int long long 

#define P 1000000007
void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int>f(n,0);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<n;j++) 
		if((s[j]-'a')==i&&k)
		{
			f[j]=1;
			k--;
		}
	}
	string ans="";
	for(int j=0;j<n;j++) if(f[j]) ans+=s[j];
	
//	cout<<ans<<"\n";
	int l=ans.size();
	vector<int>dp(l,0);
	for(auto i:s)
	{
		vector<int>ndp=dp;
		for(int j=0;j<l;j++) 
        if(i==ans[j]) ndp[j+1]=(ndp[j+1]%P+dp[j]%P)%P;
		dp=ndp;
	}
	cout<<dp[l]%P<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

