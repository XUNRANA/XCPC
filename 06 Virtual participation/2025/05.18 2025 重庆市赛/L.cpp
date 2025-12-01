#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
void solve()
{
    int n;
    cin>>n;
    vector<int>a;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s=="Push")
        {
            int t;
            cin>>t;
            a.push_back(t);
            sum=(sum+t)%mod;
        }
        else if(s=="Pop")
        {
            sum=(sum-a.back()+mod)%mod;
            a.pop_back();
        }
        else
        {
            if(a.size()<n-i)
            {
                int tt=a.size();
                for(int j=0;j<tt;j++) a.push_back(a[j]);
            }
            sum=sum*2%mod;
        }
        cout<<sum<<endl;
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