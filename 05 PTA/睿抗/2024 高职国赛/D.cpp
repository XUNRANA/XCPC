#include <bits/stdc++.h>
using namespace std;
#define int long long

int c[110];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        c[x]++;

        int ans=0;
        int s=0;
        int idx=(i+1)/2;
        for(int j=0;j<=100;j++)
        {
            if(i&1)
            { 
                if(s<idx&&s+c[j]>=idx)
                {
                    ans=2*j;
                    break;
                }
            }
            else
            {
                if(s<idx&&s+c[j]>=idx)
                {
                    if(s+c[j]>idx) ans=2*j;
                    else
                    {
                        for(int j1=j+1;j1;j1++) 
                        if(c[j1]) 
                        {
                            ans=j1+j;
                            break;
                        }
                    }
                    break;
                }
            }
            s+=c[j];
        }
        cout<<ans/2;
        if(ans&1) cout<<".5\n";
        else cout<<".0\n";
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

