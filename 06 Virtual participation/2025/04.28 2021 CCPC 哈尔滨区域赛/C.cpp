#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100010
struct node
{
    map<int,int>cnt;//每个数的出现次数
    set<int>st;// 出现次数为mx的数
    int mx=1;//出现次数最多的次数
    int ans=0;// 每个节点的答案
    void add(int x)
    {
        cnt[x]++;
        if(cnt[x]>mx)
        {
            mx=cnt[x];
            st.clear();
            st.insert(x);
        }
        else if(cnt[x]==mx) st.insert(x);
    }
    int size() 
    {
        return st.size();
    }
    void clear()
    {
        if(mx>1)
        {
            cnt.clear();
            for(auto x:st) cnt[x]=1;
            mx=1;
        }
    }
}sub[N];
int id[N];
int tot;
int n,c[N];
vector<int>g[N];
void dfs(int u)
{
    id[u]=++tot;
    int mx_siz=0,mx_son=-1;
    for(auto v:g[u])
    {
        dfs(v);
        if(sub[id[v]].size()>mx_siz)
        {
            mx_siz=sub[id[v]].size();
            mx_son=v;
        }
    }
    if(mx_son==-1)//叶子节点
    {
        sub[id[u]].add(c[u]);
        sub[id[u]].ans=1;
        return ;
    }
    id[u]=id[mx_son];//等于最大的子树
    for(auto v:g[u])
    {
        if(v==mx_son) continue;
        for(auto x:sub[id[v]].st) sub[id[u]].add(x);//轻儿子合并 
        sub[id[u]].ans+=sub[id[v]].ans;
    }
    sub[id[u]].ans-=(sub[id[u]].mx-1);
    sub[id[u]].clear();
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        g[f].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1);
    cout<<sub[id[1]].ans<<"\n";
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
