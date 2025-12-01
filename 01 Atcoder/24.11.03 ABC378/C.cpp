#include <bits/stdc++.h>
using namespace std;

int n,a[200010],ans[200010];
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(mp.count(a[i])) ans[i]=mp[a[i]];
		else ans[i]=-1;
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
