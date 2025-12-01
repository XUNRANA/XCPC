#include <bits/stdc++.h>
using namespace std;
#define int long long

string a[100010];
string b[100010];
set<int>g[300010];

int fa[300010];
int ans;
int n,m;
void dfs(int x)
{
    if(x<=n) ans++;
    for(auto v:g[x])
    {
        dfs(v);
    }
}
void solve()
{
    cin>>n>>m;
    set<string>st;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        if(isdigit(a[i][0])) ;
        else st.insert(a[i]);
        st.insert(b[i]);
    }
    map<string,int>mp;
    int idx=n;
    for(auto i:st) mp[i]=++idx;

    for(int i=1;i<=m;i++)
    {
        int u,v=mp[b[i]];


        if(!isdigit(a[i][0])) u=mp[a[i]];
        else u=stoi(a[i]);

        fa[u]=v;
        g[v].insert(u);
    }

    while(1)
    {
        char op;
        cin>>op;
        if(op=='T')
        {
            int x;
            string y;
            cin>>x>>y;

            g[fa[x]].erase(x);
            
            fa[x]=mp[y];
            g[fa[x]].insert(x);
        }
        else if(op=='Q')
        {
            string y;
            cin>>y;
            int x=mp[y];
            ans=0;
            dfs(x);
            cout<<ans<<"\n";
        }
        else break;

    }

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
