#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,c,d,a11,b11,a[250010];
void solve()
{
	cin>>n>>c>>d;
	for(int i=1;i<=n*n;i++) cin>>a[i];
	sort(a+1,a+1+n*n);
	a11=a[1];
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		b11=a11;
		for(int j=1;j<=n;j++)
		{
			ans.push_back(b11);
			b11+=d;
		}
		a11+=c;
	}
	sort(ans.begin(),ans.end());
	for(int i=1;i<=n*n;i++) if(a[i]!=ans[i-1]) 
	{
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
