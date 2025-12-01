#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,k,t;
void solve()
{
	cin>>n>>k;
	vector<int>a,b;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		if(t) a.push_back(t);
	}
	sort(a.begin(),a.end(),greater<int>());
	int ans;
	if(a.size()) ans=a[0];
	else ans=0;
	
	for(int i=1;i<a.size();i++) b.push_back(a[i]);
	
	for(int i=0;i<b.size()/(k-1)*(k-1);i++) ans=ans*b[i]%P;
	cout<<ans%P<<"\n";
}
/*
3
8 3
44 5 2018 8 8 2024 8 28
5 4
4 5 5 1 0
5 2
0 0 0 0 0
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
