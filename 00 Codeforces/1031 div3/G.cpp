#include <bits/stdc++.h>
using namespace std;
#define int long long

int p[200010];
void solve() 
{
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    int sl=0;
    int sd=0;
    for(int i=1;i<=n;i++) sl+=(1+i)*i/2;
    p[0]=0;
    for(int i=1;i<=n;i++) 
    if(s[i]=='1') p[i]=p[i-1]+1;
    else p[i]=p[i-1]-1;
    sort(p,p+1+n);
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        if(i) sd+=i*p[i]-sum;
        sum+=p[i];
    }
    cout<<(sl+sd)/2<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}