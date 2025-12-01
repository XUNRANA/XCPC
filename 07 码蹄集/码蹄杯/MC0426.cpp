#include <bits/stdc++.h>
using namespace std;



int d[26][26];
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<26;i++) 
    for(int j=0;j<26;j++) d[i][j]=1e9;
    
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        d[s[0]-'a'][s.back()-'a']=1;
    }

    for(int k=0;k<26;k++)
    for(int i=0;i<26;i++) 
    for(int j=0;j<26;j++)
    {
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }

    while(q--)
    {
        char x,y;
        cin>>x>>y;
        if(d[x-'a'][y-'a']==1e9) cout<<"No\n";
        else cout<<"Yes\n";
    }

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}