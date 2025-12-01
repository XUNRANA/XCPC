#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    if(n==1)cout<<2<<endl;
    else if(n==2)cout<<16<<endl;
    else if(n==3)cout<<32<<endl;
    else cout<<4<<endl;

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