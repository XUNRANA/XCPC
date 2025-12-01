#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int a=0,ap=0,apc=0;
	int j=1;
	vector<int>ai,pi,ci;
	for(auto i:s)
	{
		if(i=='A') ai.push_back(j);
		else if(i=='P') pi.push_back(j);
		else if(i=='C') ci.push_back(j);
		j++;
		
		if(i=='A') a++;
		else if(i=='P')
		{
			if(a) a--,ap++;
		}
		else
		{
			if(ap) ap--,apc++;
		}
	}
	
	vector<int>f(n+1,0);
	vector<vector<int>>ans;
//	cout<<apc<<"\n";
	j=0;
	int k=0;
	for(int i=0;i<apc;i++) 
	{
		while(pi[j]<ai[i]) j++;
		while(ci[k]<pi[j]) k++;
		ans.push_back({ai[i],pi[j],ci[k]});
		f[ai[i]]=f[pi[j]]=f[ci[k]]=1;
		j++;
		k++;
	}
	string res="";
	for(int i=1;i<=n;i++) if(f[i]==0) res+=s[i-1];
	if(res=="") res="Perfect";
	cout<<res<<"\n";
	
	cout<<apc<<"\n";
	for(auto i:ans)
	{
		for(auto j:i) cout<<j<<" ";
		cout<<"\n";
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
