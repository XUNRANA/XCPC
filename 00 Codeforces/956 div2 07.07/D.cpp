#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[100010],b[100010];
void solve()
{
	cin>>n;
	map<int,int>ma;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ma[a[i]]=i;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i]) continue;
		if(!ma.count(b[i]))
		{
			cout<<"NO\n";
			return ;
		}
		ans++;
		int j=ma[b[i]];
		swap(a[i],a[j]);//a一个数组交换 
		ma[a[i]]=i;
		ma[a[j]]=j;
	}
	if(ans%2==0) cout<<"YES\n";
	else cout<<"NO\n"; 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
