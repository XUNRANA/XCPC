#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100010];
void solve()
{
    int n;
    cin>>n;
    int ans=0,res=1;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        a[x]+=y;
        if(a[x]>ans)
        {
            ans=a[x];
            res=x;
        }
    }
    cout<<res<<" "<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

