#include <bits/stdc++.h>
using namespace std;
int b[3];
void solve()
{
	int n,m,q,x;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++) cin>>b[i]; 
	if(b[1]>b[2]) swap(b[1],b[2]);
	while(q--) 
	{
		cin>>x;
//		1 2 3 3 3 3
		if(x>b[1]&&x<b[2]) cout<<(b[2]-b[1]-1+1)/2<<"\n";
		else if(x>b[2]) cout<<n-b[2]<<"\n";
		else cout<<b[1]-1<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
