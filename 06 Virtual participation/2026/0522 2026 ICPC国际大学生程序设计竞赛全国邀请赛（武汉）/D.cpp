#include <bits/stdc++.h>
using namespace std;

#define int long long
int ans[]={0,0,1,2,2,3,3,3,3,4,4,4,4,4,5,5,5};


// 100010110011

// 100000000000 19

// 110011010001

// 110110000000 20
void fx(int x)
{
    for(int i=0;i<32;i++)
    if(x>>i&1) cout<<"1";
    else cout<<"0";
    cout<<"\n";    
}
void solve()
{
    int n;
    cin>>n;
    // fx(n);
    if(n<=16) cout<<ans[n]<<"\n";
    else
    {
        int l=16,r=27;
        int res=6;
        while(n>r)
        {
            res++;
            int pl=l;
            l=r;
            r=pl*2;
        }
        cout<<res<<"\n";
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