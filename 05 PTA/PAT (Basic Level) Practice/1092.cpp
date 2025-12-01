#include <bits/stdc++.h>
using namespace std;
#define int long long

int c[1010];
void solve()
{
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            cin>>x;
            c[j]+=x;
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,c[i]);
    cout<<mx<<"\n";
    int f=0;
    for(int i=1;i<=n;i++) if(mx==c[i]) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
