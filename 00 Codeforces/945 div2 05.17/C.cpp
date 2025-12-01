#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans[100010];
void solve()
{
	cin>>n;
	int f,j=n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans[i]=0;
		if(a[i]==1) f=i&1;
	}
	if(f)
	{
		vector<int>v;
		for(int i=2;i<=n-2;i+=2) v.push_back(a[i]);
		sort(v.begin(),v.end());
		for(auto i:v) ans[i]=j--;
		v.clear();
		for(int i=1;i<=n;i++) if(ans[a[i]]==0) v.push_back(a[i]);
		sort(v.begin(),v.end());
		for(auto i:v) ans[i]=j--;
	}
	else
	{
		vector<int>v;
		for(int i=3;i<=n-1;i+=2) v.push_back(a[i]);
		sort(v.begin(),v.end());
		for(auto i:v) ans[i]=j--;
		v.clear();
		for(int i=1;i<=n;i++) if(ans[a[i]]==0) v.push_back(a[i]);
		sort(v.begin(),v.end());
		for(auto i:v) ans[i]=j--;
	}
	for(int i=1;i<=n;i++) cout<<ans[a[i]]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
