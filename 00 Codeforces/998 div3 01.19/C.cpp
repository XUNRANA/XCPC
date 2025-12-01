#include <bits/stdc++.h>
using namespace std;
int n,k,x;
void solve()
{
	cin>>n>>k;
	multiset<int>st;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(st.count(k-x))
		{
			st.erase(st.find(k-x));
			ans++;
		}
		else st.insert(x);
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
