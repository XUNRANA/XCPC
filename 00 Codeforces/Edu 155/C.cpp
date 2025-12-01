#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[200010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=2e5;i++) jc[i]=jc[i-1]*i%P;
}
void solve()
{
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<s.size();i++)
    if(s[i]==s[i-1]) cnt++;
    
    int ans=1;
    
    int c=1;
    for(int i=1;i<s.size();i++)
    if(s[i]==s[i-1]) c++;
    else
    {
        ans=ans*c%P;
        c=1;
    }
    ans=ans*c%P;
    ans=ans*jc[cnt]%P;
    cout<<cnt<<" "<<ans<<"\n";
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
// 11111
// 5*4*3*2*1
// 00000
// 5*4*3*2*1


//0011
// 4
// 240

// 0000011111
