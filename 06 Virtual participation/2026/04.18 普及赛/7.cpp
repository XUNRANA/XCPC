#include <bits/stdc++.h>
using namespace std;
#define int long long
int is2(int x)
{
    int a=sqrt(x);
    return a*a==x;
}
set<int>st;
int is3(int x)
{
    return st.count(x);
}
void init()
{
    for(int i=1;i*i*i<(1ll<<31);i++)
    {
        // cout<<i*i*i<<"???\n";
        st.insert(i*i*i);
    }
}
void solve()
{
    int x;
    cin>>x;
    if(x%3==0&&is3(x/3)) cout<<x<<" is a triple flower\n";
    else if(x%2==0&&is2(x/2)) cout<<x<<" is a double flower\n";
    else cout<<x<<" is "<<x<<"\n";
}
signed main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}