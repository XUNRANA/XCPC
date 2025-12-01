#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int ans;
int cnt;
int ch[1000010][26];
int ss[1000010];
void insert(string s)
{
    int now=0;
    for(auto i:s)
    {
        if(!ch[now][i-'a']) ch[now][i-'a']=++cnt;
        now=ch[now][i-'a'];
        ans+=ss[now];
        ans%=P;
        ss[now]++;
    }
}
void solve()
{
    int n;
    cin>>n;
    int ans1=0;
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
        ans1+=s.size();
    }
    // cout<<ans1<<" "<<ans<<"\n";
    cout<<(2*ans%P+ans1)%P<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}