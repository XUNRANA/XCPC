#include <bits/stdc++.h>
using namespace std;
int nxt[1000010][26];
int res[1000010];
void solve () 
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    s=" "+s;
    for(int i=n+1;i>=1;i--)
    {
        if(i==n+1) for(int j=0;j<26;j++) nxt[i][j]=n+1;
        else 
        {
            for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i]-'a']=i;
        }
    }
    set<int>st;
    res[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        res[i]=res[i+1];
        st.insert(s[i+1]);
        if(st.size()==k) 
        {
            st.clear();
            res[i]++;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        string t;
        cin>>t;
        int j=0;
        for(auto i:t)
        {
            j=nxt[j+1][i-'a'];
            if(j>n) break;
        }
        if(j>n) cout<<"0\n";
        else cout<<res[j]<<"\n";
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)
    solve();
}