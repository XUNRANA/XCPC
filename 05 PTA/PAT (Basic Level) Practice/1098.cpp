#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[110],b[110];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int mi=a[1];
    int mx=b[1];
    for(int i=1;i<=n;i++)
    {
        mi=min(mi,a[i]);
        mx=max(mx,b[i]);
    }
    if(mi>mx) cout<<"Yes "<<mi-mx<<"\n";
    else cout<<"No "<<mx-mi+1<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
