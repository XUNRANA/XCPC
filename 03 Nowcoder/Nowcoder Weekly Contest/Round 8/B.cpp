#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,s1,x,y,a[100010];
void solve()
{
    s=s1=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    cin>>x>>y;
    if(x>y) swap(x,y);
    for(int i=x;i<=y-1;i++) s1+=a[i];
    cout<<min(s1,s-s1)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
