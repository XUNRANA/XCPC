#include <bits/stdc++.h>
using namespace std;



string s[2010];
int f[2010];
vector<int>g[2010];
int vis[2010];
int d[2010];
int pre[2010];
void solve()
{
    int n;
    cin>>n;
    map<pair<string,int>,int>mp;

    set<pair<string,int>>st;

    for(int i=1;i<=2*n;i++)
    {
        cin>>s[i]>>f[i];
        st.insert({s[i],f[i]});
    }

    vector<pair<string,int>>vt;
    for(auto i:st) vt.push_back(i);
    for(int i=0;i<vt.size();i++) mp[vt[i]]=i;
    for(int i=1;i<=2*n;i+=2)
    {
        int u=mp[{s[i],f[i]}];
        int v=mp[{s[i+1],f[i+1]}];
        g[u].push_back(v);
    }

    vector<int>ans;
    n=vt.size();
    for(int i=0;i<n;i++)
    {
        auto p=vt[i];
        p.second^=1;
        if(!mp.count(p)) continue;
        priority_queue< array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
        int s=i;
        int t=mp[p];
        for(int j=0;j<n;j++) vis[j]=0,d[j]=1e9;
        d[s]=0;
        q.push({0,s});
        while(!q.empty())
        {
            int u=q.top()[1];
            q.pop();

            if(vis[u]) continue;
            vis[u]=1;
            for(auto v:g[u])
            {
                if(d[v]>d[u]+1)
                {
                    d[v]=d[u]+1;
                    pre[v]=u;
                    q.push({d[v],v});
                }
            }
        }
        if(d[t]!=1e9)
        {
            vector<int>pa;
            pa.push_back(t);
            while(pre[t]!=s)
            {
                pa.push_back(pre[t]);
                t=pre[t];
            }
            pa.push_back(pre[t]);
            if(!ans.size()) ans=pa;
            else if(pa.size()<ans.size()) ans=pa;
        }
    }

    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) 
    {
        if(i!=0&&i!=ans.size()-1) cout<<vt[ans[i]].first<<" "<<vt[ans[i]].second<<" ";
        cout<<vt[ans[i]].first<<" "<<vt[ans[i]].second<<" ";
    }
    cout<<"= ";
    cout<<vt[ans[0]].first<<" "<<vt[ans[0]].second<<" ";
    cout<<vt[ans.back()].first<<" "<<vt[ans.back()].second;
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
