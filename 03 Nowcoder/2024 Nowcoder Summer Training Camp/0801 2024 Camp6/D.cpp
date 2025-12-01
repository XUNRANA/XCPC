#include <bits/stdc++.h>
using namespace std ;
const int MAXN=2e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"


vector<int > edges[MAXN];

stack<int> stk;
// instk：是否在栈中  scc：每个点所属的强连通分量编号  cscc：强连通分量的数量
int dfsn[MAXN], low[MAXN], instk[MAXN], scc[MAXN], cnt, cscc;
void tarjan(int p,int pa)
{
    low[p] = dfsn[p] = ++cnt;
    instk[p] = 1;
    stk.push(p); // 进栈
    for (auto q : edges[p])
    {
        if(q==pa) continue;
        if (!dfsn[q]) // 未访问过
        {
            tarjan(q,p); // 递归地搜索
            low[p] = min(low[p], low[q]);
        }
        else if (instk[q]==1) // 访问过，且q可达p
            low[p] = min(low[p], dfsn[q]);
    }
    if (low[p] == dfsn[p]) // 发现强连通分量的根
    {
        int top;
        cscc++;
        do
        {
            top = stk.top();
            stk.pop();
            instk[top] = 2;
            scc[top] = cscc; // 记录所属的强连通分量
        } while (top != p); // 直到弹出p才停止
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int ,int > > lun,qie;
    // vector<vector<int > > G(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        string s;
        cin>>u>>v;
        cin>>s;
        if(s=="Lun"){
            // G[u].push_back(v);
            // G[v].push_back(u);
            edges[u].push_back(v);
            edges[v].push_back(u);
            lun.push_back({u,v});
        }else{
            qie.push_back({u,v});
        }
    }
    for(int i=1;i<=n;i++){
        if(not instk[i])
        tarjan(i,0);
    }
    
    // for(int i=1;i<=n;i++){
    //     cout<<scc[i]<<endl;
    // }
    // return ;

    vector<pair<int ,int > > ans1;
    for(auto t:lun){
        if(scc[t.first]==scc[t.second]){
            ans1.push_back({t.first,t.second});
        }
    }
    int fa[n+1];
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    function <int (int ) > find=[&](int x){
        if(x==fa[x]) return x;
        int tmp=find(fa[x]);
        return fa[x]=tmp;
    };
    int tot=cscc;
    vector<pair<int ,int > > ans2;
    for(auto t:qie){
        int st1=find(scc[t.first]);
        int st2=find(scc[t.second]);
        if(st1!=st2){
            ans2.push_back({t.first,t.second});
            fa[st2]=st1;
            tot--;
        }
    }
    int ok=1;
    // if(tot==1){
    //     ok=1;
    // }else{
    //     ok=0;
    // }
    int root=find(scc[1]);
    for(int i=2;i<=n;i++){
        int st=find(scc[i]);
        if(st!=root){
            ok=0;
            break;
        }
    }
    if(ok==1){
        cout<<"YES"<<endl;
        ll cnt=ans1.size()+ans2.size();
        cout<<cnt<<endl;
        for(auto t: ans1){
            cout<<t.first<<" "<<t.second<<endl;
        }
        for(auto t: ans2){
            cout<<t.first<<" "<<t.second<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
