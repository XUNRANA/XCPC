#include <bits/stdc++.h>
using namespace std;
int a[100010];
void solve()
{
	int n,m,j,x;
	string s,t;
	cin>>n>>m>>s;
	set<int>st;
	for(int i=1;i<=m;i++) cin>>x,st.insert(x);
	cin>>t;
	sort(t.begin(),t.end());
	j=0;
	for(auto i:st)
	{
		s[i-1]=t[j++];
	}
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
