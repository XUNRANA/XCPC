#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,x,y;
	cin>>n>>x;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>y;
		s+=y;
	}
	if(n*x==s) cout<<"YES\n";
	else cout<<"NO\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

