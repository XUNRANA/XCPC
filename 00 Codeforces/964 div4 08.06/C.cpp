#include <bits/stdc++.h>
using namespace std;
int n,s,m,p,l,r,res;
void solve()
{
	cin>>n>>s>>m;
	p=0;
	res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r;
		res=max(res,l-p);
		p=r;
	}
	res=max(res,m-p);
	if(res>=s) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
