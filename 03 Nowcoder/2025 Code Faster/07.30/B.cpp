#include <bits/stdc++.h>
using namespace std;
int n,a[26];
string s;
void solve()
{
    cin>>n;
    for(int i=0;i<26;i++) cin>>a[i];
    cin>>s;
    vector<char>ch;
    vector<int>cnt;
    ch.push_back(s[0]);
    cnt.push_back(1);
    for(int i=1;i<n;i++)
    {
        if(s[i]==ch.back()) cnt.back()++;
        else
        {
            ch.push_back(s[i]);
            cnt.push_back(1);
        }
    }

    int f=1;
    for(int i=0;i<ch.size();i++)
    {
        // cout<<ch[i]<<" "<<cnt[i]<<"\n";
        if((!a[ch[i]-'a'])||cnt[i]%a[ch[i]-'a']!=0)
        {
            f=0;
        }
    }
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}