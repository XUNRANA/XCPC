#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
void solve()
{
    string s;
    cin>>s;
    vector<int>num,cnt;
    num.push_back(s[0]-'0');
    cnt.push_back(1);
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            num.push_back(s[i]-'0');
            cnt.push_back(1);
        }
        else cnt.back()++;
    }

    int ans=0;
    for(int i=1;i<num.size();i++)
    {
        if(num[i]==num[i-1]+1)
        {
            ans+=min(cnt[i],cnt[i-1]);
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}