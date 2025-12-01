#include <bits/stdc++.h>
using namespace std;
int n,m,q,k,a[1010];
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
    }
    while(q--)
    {
        cin>>k;
        cout<<a[k]<<"\n";
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
