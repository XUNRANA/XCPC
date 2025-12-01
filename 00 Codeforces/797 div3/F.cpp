#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[210];
int vt[210];
string s;
int fx(string s)
{
    string p=s;
    s=s+s;
    // cout<<s<<" "<<p<<"??\n";
    for(int i=1;i+p.size()-1<s.size();i++)
    {
        if(s.substr(i,p.size())==p) return i;
        // cout<<s.substr(i,p.size())<<"\n";
        // cout<<p<<"\n";
    }
    // return 1;
}
int lcm(int x,int y)
{
    return x/__gcd(x,y)*y;
}
void solve() 
{
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i],vt[i]=0;
    int ans=1;
    for(int i=1;i<=n;i++)
    if(!vt[i])
    {
        string res="";
        int j=i;
        while(!vt[j])
        {
            res+=s[j];
            vt[j]=1;
            j=a[j];
        }
        ans=lcm(ans,fx(res));
        // cout<<i<<" "<<res<<" "<<fx(res)<<"?\n";
    }
    cout<<ans<<"\n";
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