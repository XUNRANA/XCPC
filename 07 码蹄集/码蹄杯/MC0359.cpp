#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int a[1000010];
int r[1000010];
int p[1000010];
int R[1000010];

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i],r[i]=1;
    int l=1;
    for(int i=1;i<=n;i++) 
    {
        if(i>1)
        {
            if(a[i]-a[i-1]==a[l+1]-a[l]) r[i]+=i-l;
            else 
            {
                l=i-1;
                r[i]++;
            }
        }
        p[i]=p[i-1]+r[i];
    }
    
    R[n]=n;
    l=a[n]-a[n-1];
    for(int i=n-1;i>=1;i--)
    {
        if(a[i+1]-a[i]==l) R[i]=R[i+1];
        else 
        {
            l=a[i+1]-a[i];
            R[i]=i+1;
        }
    }


    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r) cout<<"1\n";
        else 
        {
            if(R[l]>=r) cout<<(r-l+1)*(r-l+1+1)/2<<"\n";
            else
            {
                int ans=(R[l]-l+1)*(R[l]-l+1+1)/2;
                ans+=p[r]-p[R[l]];
                cout<<ans<<"\n";
            }
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
