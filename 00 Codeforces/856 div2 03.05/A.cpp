#include <bits/stdc++.h>
using namespace std;
#define int long long
string t,x1,x2;
int n;
void solve()
{
	cin>>n;
	x1=x2="";
	for(int i=1;i<=2*n-2;i++)
	{
		cin>>t;
		if(t.size()==n-1) 
		{
			if(x1=="") x1=t;
			else x2=t;
		}
	}
	reverse(x1.begin(),x1.end());
	if(x1==x2) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
