#include <bits/stdc++.h>
using namespace std;

int a[100010];
void solve()
{
    int n;
    cin>>n;
    int s0=0;
    int s1=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    string s;
    cin>>s;   
    s=" "+s;
    for(int i=1;i<=n;i++) 
    if(s[i]=='1') s1^=a[i];
    else s0^=a[i];
    for(int i=1;i<=n;i++) a[i]^=a[i-1];
    int q;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r;
            cin>>l>>r;
            s1^=a[r]^a[l-1];
            s0^=a[r]^a[l-1];
        }
        else 
        {
            int f;
            cin>>f;
            if(f) cout<<s1<<" ";
            else cout<<s0<<" ";
        }
    }
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}