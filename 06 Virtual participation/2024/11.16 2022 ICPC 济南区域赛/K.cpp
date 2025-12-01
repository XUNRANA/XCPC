#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,x;
	cin>>n;
	set<int>st;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		st.insert(x);
		if(st.count(x+1)) continue;
		else ans++;
	}
	cout<<ans<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
