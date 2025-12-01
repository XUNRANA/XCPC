#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,mx,cnt;
void solve()
{
	cin>>n;
	while(n--)
	{
		cin>>t;
		if(t>mx) mx=t,cnt=1;
		else if(t==mx) cnt++;
 	} 
 	if(cnt&1) cout<<"Alice\n";
 	else cout<<"Bob\n";	
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}
