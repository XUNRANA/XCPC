#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[110];
int in[10010];
void fx(int x)
{
    if(x&1) x=(3*x+1)/2;
    else x/=2;
    while(x!=1)
    {
        in[x]++;
        if(x&1) x=(3*x+1)/2;
        else x/=2;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) fx(a[i]);
    int f=0;
    for(int i=n;i>=1;i--) if(!in[a[i]]) 
    {
        if(f) cout<<" ";
        cout<<a[i];
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