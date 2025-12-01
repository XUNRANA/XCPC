#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int c0=0,c1=0;
    for(int i=0;i<n;i++) 
    {
        if(a[i]=='0')
        {
            if(i&1) c1++;
            else c0++;
        }
    }
    for(int i=0;i<n;i++) 
    {
        if(b[i]=='0')
        {
            if(i&1) c0++;
            else c1++;
        }
    }
    // cout<<c1<<" "<<c0<<"\n";
    if(n&1)
    {
        if(min(c0,n/2+1)+min(c1,n/2)>=n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else 
    {
        if(min(c0,n/2)+min(c1,n/2)>=n) cout<<"YES\n";
        else cout<<"NO\n";
    } 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
