#include <bits/stdc++.h>
using namespace std;
#define int long long


int n,q,l,r;
int a[250010];
int s[250010];
int lowbit(int x)
{
    return x&-x;
}
void solve()
{

    cin>>n>>q;

    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        int ans=0,f=0;
        while(x!=1)
        {
            x/=2;
            ans++;
            if(x!=1&&lowbit(x+1)==(x+1)) f=1;
        }
        a[i]=ans+f;
        s[i]=s[i-1]+a[i];
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n"; 

    while(q--)
    {
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}