#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int s,m,n;
    cin>>s>>m>>n;
    if(s-m<=0) cout<<"1\n";
    else 
    {
        if(n>=m) cout<<"WanMei!\n";
        else cout<<1+(s-m+(m-n-1))/(m-n)<<"\n";
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}