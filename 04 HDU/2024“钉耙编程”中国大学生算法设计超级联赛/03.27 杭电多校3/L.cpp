#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,d;
int a[100010];
void solve()
{
    cin>>n>>l>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+2,a+n+1);
    int idx=-1;
    for(int i=n;i>=2;i--) 
    if(a[i]<l)
    {
        idx=i;
        break;
    }
    if(a[1]>=l)
    {
        if(idx>=4)
        {
            int mx=max(a[1],a[idx]);
            int mi=min(a[1],a[2]);
            if(mx-mi>d)
            {
                cout<<"Yes\n";
                return ;
            }
        }
    }
    else if(idx>=3)
    {
        int mx=max(a[1],a[n]);
        int mi=min(a[1],a[2]);
        if(mx-mi>d)
        {
            cout<<"Yes\n";
            return ;
        }
    }
    cout<<"No\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}