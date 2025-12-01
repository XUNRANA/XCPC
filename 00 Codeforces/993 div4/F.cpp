#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,x,a[200010],b[200010];
void solve()
{
    cin>>n>>m>>q;
    int sa=0,sb=0;
    for(int i=1;i<=n;i++) cin>>a[i],sa+=a[i];
    for(int i=1;i<=m;i++) cin>>b[i],sb+=b[i];
    vector<int>ma(4e5+10,0);
    vector<int>mb(4e5+10,0);
    for(int i=1;i<=n;i++) if(sa-a[i]+2e5>=0&&sa-a[i]+2e5<=4e5) ma[sa-a[i]+2e5]=1;
    for(int i=1;i<=m;i++) if(sb-b[i]+2e5>=0&&sb-b[i]+2e5<=4e5) mb[sb-b[i]+2e5]=1;
    while(q--)
    {
        cin>>x;
        if(x==0) 
        {
            if(ma[2e5]==1||mb[2e5]==1) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        int f=0;
        int t=x;
        if(x<0) x=-x;
        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                if(t>0)
                {
                    if((ma[i+2e5]&&mb[x/i+2e5])||(ma[x/i+2e5]&&mb[i+2e5])) 
                    {
                        f=1;
                        cout<<"YES\n";
                        break;
                    }
                    else if((ma[-i+2e5]&&mb[-x/i+2e5])||(ma[-x/i+2e5]&&mb[-i+2e5])) 
                    {
                        f=1;
                        cout<<"YES\n";
                        break;
                    }

                }
                else
                {
                    if((ma[-i+2e5]&&mb[x/i+2e5])||(ma[x/i+2e5]&&mb[-i+2e5])) 
                    {
                        f=1;
                        cout<<"YES\n";
                        break;
                    }
                    else if((ma[i+2e5]&&mb[-x/i+2e5])||(ma[-x/i+2e5]&&mb[i+2e5])) 
                    {
                        f=1;
                        cout<<"YES\n";
                        break;
                    }
                }
            }
        }
        if(!f) cout<<"NO\n"; 
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
