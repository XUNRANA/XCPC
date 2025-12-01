#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+1+2*n);
    for(int i=1;i<=2*n;i+=2) 
    if(a[i]!=a[i+1]) 
    {
        cout<<"-1";
        return ;
    }
    for(int i=1;i<=2*n;i+=2) cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=2*n;i+=2) cout<<a[i]<<" ";
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

