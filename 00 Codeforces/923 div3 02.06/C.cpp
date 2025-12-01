#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,k,t1;
	cin>>n>>m>>k;
	map<int,int>a,b;
	while(n--)
	{
		cin>>t1;
		if(t1>=1&&t1<=k) a[t1]=1;
	}
	while(m--)
	{
		cin>>t1;
		if(t1>=1&&t1<=k) b[t1]=1;
	}
	if(a.size()<k/2||b.size()<k/2) cout<<"NO\n";
	else
	{
	    map<int,int>c;
		for(auto i:a) c[i.first]=1;
		for(auto i:b) c[i.first]=1;
		if(c.size()==k) cout<<"YES\n";
		else cout<<"NO\n";	
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}
