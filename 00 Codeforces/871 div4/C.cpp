#include <bits/stdc++.h>
using namespace std;
int a[4];
void solve()
{
    int n;
    cin>>n;
    a[1]=a[2]=a[3]=1e9;
    for(int i=1;i<=n;i++)
    {
        int c;
        string b;
        cin>>c>>b;
        if(b=="01") a[1]=min(a[1],c);
        else if(b=="10") a[2]=min(a[2],c);
        else if(b=="11") a[3]=min(a[3],c);
    }
    int ans=min(a[3],a[1]+a[2]);
    if(ans>=1e9) ans=-1;
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
