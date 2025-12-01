#include <bits/stdc++.h>
using namespace std;
int n,x,y,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>x>>y;
    for(int i=1;i<=n;i++) 
    if(a[i]==x)
    {
        if(a[i-1]==y||a[i+1]==y) cout<<"Yes\n";
        else cout<<"No\n";
        return ;
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
