#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+9;
int main()
{
    long long fir=1,sec=1;
    int m,op,x;
    cin>>m;
    while(m--)
    {
        cin>>op>>x;
        if(op==1) fir=1ll*fir*x%mod;
        else sec=1ll*sec*x%mod;
    }
    cin>>m;
    while(m--)
    {
        cin>>op>>x;
        if(op==1) sec=1ll*sec*x%mod;
        else fir=1ll*fir*x%mod;
    }
    if(fir==sec) cout<<"YES\n";
    else cout<<"NO\n";
}
