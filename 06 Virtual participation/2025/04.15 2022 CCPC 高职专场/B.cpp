#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,d[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>d[i];
	vector<int>a;
	if(n==1)
	{
		cout<<"0\n";
		return ;
	}
	for(int i=1;i<n;i++) 
	{
		int u,v;
		cin>>u>>v;
		a.push_back(min(d[u],d[v]));
	}
	sort(a.begin(),a.end());
	int ans=k*a[0];
	for(int i=0;i<n-1-k;i++) ans+=a[i];
	cout<<ans<<"\n";
} 

/*
5 0
5 4 3 2 1
1 2
2 4
3 5
1 5
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

