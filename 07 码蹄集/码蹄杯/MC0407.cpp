#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int a[1000010];
int b[1000010]; 
int lowbit(int x)
{
    return x&-x;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++) ans=(ans+a[i])%P;
    int cnt=0;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            if(cnt==n)
            {
                ans=ans*2%P;
            }
            else
            {
                for(int i=1;i<=n;i++) 
                {
                    if(!b[i]&&lowbit(a[i])==a[i]) b[i]=1,cnt++;
                    
                    if(b[i]==1) 
                    {
                        ans=(ans+a[i])%P;
                        a[i]=a[i]*2%P;
                    }
                    else 
                    {
                        ans=(ans+lowbit(a[i]))%P;
                        a[i]+=lowbit(a[i]);
                    }
                }
            }
        }
        else if(op==2) 
        {
            cout<<ans<<"\n";
        }
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

