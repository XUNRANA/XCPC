#include <bits/stdc++.h>
using namespace std;
#define N 5010
int x[N],y[N],c[N];
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>x[i]>>y[i]>>c[i];
	cout<<n+m-1<<" "<<c[k]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
