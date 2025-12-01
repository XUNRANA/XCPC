#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[2][7];
void solve()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        c[y][x]++;
    }

    int s0=0,s1=0;
    for(int i=1;i<=6;i++)
    if(i!=4&&i!=6) 
    {
        s1+=c[1][i];
        s0+=c[0][i];
    }
    
    if(s0==s1) cout<<"LOVE "<<s0<<"\n";
    else if(s0>s1) cout<<"0 "<<s0<<"\n";
    else cout<<"1 "<<s1<<"\n";

    int mx=0;
    for(int i=1;i<=6;i++)
    {
        if(i!=4&&i!=6) 
        {
            mx=max(mx,c[1][i]+c[0][i]);
        }
    }
    cout<<mx;
    for(int i=1;i<=6;i++)
    {
        if(i!=4&&i!=6) 
        {
            if(c[1][i]+c[0][i]==mx)
            {
                cout<<" "<<i;
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
    return 0;
}