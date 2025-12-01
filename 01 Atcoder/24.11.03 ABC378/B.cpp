#include <bits/stdc++.h>
using namespace std;

int n,nq,q[110],r[110],t,d;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q[i]>>r[i];
	cin>>nq;
	while(nq--)
	{
		cin>>t>>d;
		int t1=d%q[t];
		if(t1==r[t]) cout<<d<<"\n";
		else if(t1<r[t]) cout<<d/q[t]*q[t]+r[t]<<"\n";
		else cout<<d/q[t]*q[t]+q[t]+r[t]<<"\n";
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
