#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
	cin>>n;
	set<int>st;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		st.insert(a[i-1]);
		st.insert(a[i]);
		int x=a[i]^a[i-1];
		st.insert(a[i]|a[i-1]);
		st.insert(a[i]&a[i-1]);
		st.insert(a[i]^a[i-1]);
		st.insert(x&a[i]);
		st.insert(x&a[i-1]);
		st.insert(0);
	}
	cout<<st.size()<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
