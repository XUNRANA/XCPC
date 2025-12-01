#include <bits/stdc++.h>
using namespace std;
int n,x,ans;
vector<int>f(101,-1);
int sg(int x)
{
	if(f[x]!=-1) return f[x];
	set<int>st;
	for(int i=1;i<=x;i++) st.insert(sg(x-i));
	for(int i=1;i<x;i++)
	{
		for(int j=1;j<x;j++)
		{
			int k=x-i-j;
			if(k>0) st.insert(sg(i)^sg(j)^sg(k));
		}
	}
	for(int i=0;;i++) if(!st.count(i)) return f[x]=i;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x,ans^=sg(x);
	if(ans) cout<<"w win\n";
	else cout<<"W win\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
