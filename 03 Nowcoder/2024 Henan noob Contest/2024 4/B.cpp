#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) ans=max(ans,(1<<m)-1-(a[i]^a[i-1]));
    cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
