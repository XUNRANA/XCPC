#include <bits/stdc++.h>
using namespace std;
long long n,m,u,v;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>u>>v;
    if(n<2) cout<<"0\n";
    else cout<<(n/2)*(n-n/2)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
