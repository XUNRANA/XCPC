#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,q,x;
	cin>>n>>q;
	while(q--)
	{
		cin>>x;
	    if(x%3==0) cout<<x/3+1<<" "<<x/3+1<<"\n";
	    else if(x%3==1) cout<<x/3+1<<" "<<x/3+2<<"\n";
	    else cout<<x/3+2<<" "<<x/3+1<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
