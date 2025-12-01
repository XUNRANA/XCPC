#include <bits/stdc++.h>
using namespace std;
#define int long long
string ss[210];
int c[210];
vector<pair<int,int>>g[210];
void solve()
{
    int n,k;
    string a,b;
    cin>>n>>k>>a>>b;
    map<string,int>mp;
    for(int i=1;i<n;i++)
    {
        cin>>ss[i]>>c[i];
        mp[ss[i]]=i;
    }
    ss[n]=a;
    mp[a]=n;
    for(int i=1;i<=k;i++)
    {
        string s1,s2;
        int d;
        cin>>s1>>s2>>d;
        g[mp[s1]].push_back({mp[s2],d});
        g[mp[s2]].push_back({mp[s1],d});
    }
    vector<int>d(n+1,1e18);
    vector<int>c1(n+1,0);//解放数
    vector<int>s(n+1,0);//杀伤最强
    vector<int>vt(n+1,0);
    vector<int>pre(n+1,0);
    vector<int>sz(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    d[n]=0;
    sz[n]=1;
    q.push({d[n],n});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto [v,dis]:g[u])
        {
            if(d[v]>d[u]+dis)
            {
                sz[v]=sz[u];       
                d[v]=d[u]+dis;
                c1[v]=c1[u]+1;
                s[v]=s[u]+c[v];
                pre[v]=u;
                q.push({d[v],v});
            }
            else if(d[v]==d[u]+dis)
            {
                sz[v]+=sz[u];
                if(c1[v]<c1[u]+1)
                {
                    c1[v]=c1[u]+1;
                    s[v]=s[u]+c[v];
                    pre[v]=u;
                }
                else if(c1[v]==c1[u]+1)
                {
                    if(s[v]<s[u]+c[v])
                    {
                        s[v]=s[u]+c[v];
                        pre[v]=u;
                    }
                }
            }
        }
    }
    stack<int>st;
    int id=mp[b];
    while(id!=n)
    {
        st.push(id);
        id=pre[id];
    }
    st.push(id);
    int f=0;
    while(!st.empty())
    {
        if(f) cout<<"->";
        cout<<ss[st.top()];
        st.pop();
        f=1;
    }
    cout<<"\n";
    id=mp[b];
    cout<<sz[id]<<" "<<d[id]<<" "<<s[id]<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}