#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[101];
void solve()
{
    int n,k,x;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x,cnt[x]++;
    cin>>k;
    int f=0;
    while(k--)
    {
        if(f) cout<<" ";
        cin>>x;
        cout<<cnt[x];
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

