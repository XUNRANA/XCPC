#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],j;
void solve()
{
    cin>>n;
    j=1;
    for(int i=1;i<=n;i+=2) a[i]=j++;
    if(!a[n]) for(int i=n;i>=1;i-=2) a[i]=j++;
    else for(int i=n-1;i>=1;i-=2) a[i]=j++;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
