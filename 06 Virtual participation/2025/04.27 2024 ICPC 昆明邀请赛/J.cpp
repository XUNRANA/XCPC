#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,3>>g[500010];
struct STlist
{
    int n,k;
    vector<vector<int>>Max;
    STlist(){}
    STlist(vector<int>&a){
        init(a);
    }
    void init(vector<int>&a)
    {
        n=a.size();
        k=__lg(n)+1;
        Max.assign(n,vector<int>(k));
        for(int i=0;i<n;i++) Max[i][0]=a[i];
        for(int j=1;j<k;j++)
        {
            for(int i=0;i+(1<<j)<=n;i++)
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
        }
    }
    int query(int l,int r)
    {
        int j=__lg(r-l+1);
        return max(Max[l][j],Max[r-(1<<j)+1][j]);
    }
};

void solve() 
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=m;i++)
    {
        int u,v,c,l;
        cin>>u>>v>>c>>l;
        g[u].push_back({v,c,l});
        g[v].push_back({u,c,l});
    }
    vector<vector<int>>pos(m+1);
    vector<vector<int>>len(m+1);
    vector<int>L(k+1,0);
    vector<int>col(k+1,0);
    for(int i=1;i<=k;i++)
    {
        int c,l;
        cin>>c>>l;//公司、里程
        pos[c].push_back(i);
        len[c].push_back(l);
        col[i]=c;//车票所属公司
        L[i]=l;
    }
    vector<STlist>f(m+1);
    for(int i=1;i<=m;i++) 
    {
        if(pos[i].size()==0) continue;
        f[i].init(len[i]);
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    q.push({0,0,1});
    vector<int>vt(n+1,0);
    while(!q.empty())
    {
        int idx=q.top()[0];//第几张车票
        int d=q.top()[1];//已走距离
        int u=q.top()[2];//所在城市
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v1:g[u])
        {
            int v=v1[0];
            int c=v1[1];
            int l=v1[2];
            if(col[idx]==c&&d+l<=L[idx])//同一家公司、距离还能走、直接更新
            {
                q.push({idx,d+l,v});
                continue;
            }
            if(pos[c].size()==0) continue;
            int it=upper_bound(pos[c].begin(),pos[c].end(),idx)-pos[c].begin();
            if(it==pos[c].size()) continue;
            int lf=it,ri=pos[c].size()-1;
            if(f[c].query(lf,ri)<l) continue;
            while(lf<=ri)
            {
                int mid=lf+ri>>1;
                if(f[c].query(it,mid)>=l) ri=mid-1;
                else lf=mid+1;
            }
            q.push({pos[c][lf],l,v});
        }
    }
    for(int i=1;i<=n;i++) cout<<vt[i];
    cout<<'\n';
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}