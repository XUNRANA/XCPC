#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
void solve()
{
    cin>>n;
    set<string>st;
    for(int i=1;i<=n;i++) 
    {
        string s;
        cin>>s;
        st.insert(s);
    }
    cin>>m;
    string ans="";
    int c=0;
    int mx=0;
    map<string,int>mp;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        if(st.count(s)) 
        {
            ans+='1';
            c++;
            mp[s]++;
            mx=max(mx,mp[s]);
        }
        else ans+='0';
    }
    // cout<<ans<<"\n";
    printf("%s\n",ans.c_str());
    printf("%.2f\n",100.0*c/m);
    for(auto i:mp)
    if(i.second==mx)
    printf("%s\n",i.first.c_str());


}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

