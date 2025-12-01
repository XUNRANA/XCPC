#include <bits/stdc++.h>
using namespace std;
int n,f,ans,a[300010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]!=a[n])
	{
		cout<<"0\n";
		return ;
	}
	ans=1e8;
	vector<int>b;
	b.push_back(0);
	for(int i=2;i<=n-1;i++) if(a[i]!=a[1]) b.push_back(i);
	b.push_back(n+1);
	if(b.size()==2) 
	{
		cout<<"-1\n";
		return ;
	}
	for(int i=1;i<b.size();i++) ans=min(ans,b[i]-b[i-1]-1);
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=0;
	cin>>t;
	while(t--) solve();
}
