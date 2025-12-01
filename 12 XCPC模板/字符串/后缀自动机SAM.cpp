#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000010
ll cnt[N];
int tot=1,np=1;
//fa链接边终点，ch转移边终点，len最长串长度
int fa[N],ch[N][26],len[N];
void extend(int c)
{
    //p回跳指针，np新点，q链接点，nq新链接点
    int p=np;
    //p指向旧点，np是新点
    np=++tot;
    len[np]=len[p]+1;
    //子串出现次数
    cnt[np]=1;
    //p沿链接边回跳，从旧点向新点建转移边
    for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
    //1.如果c是新字符，从新点向根节点建链接边
    if(p==0) fa[np]=1;
    else//旧字符
    {
        int q=ch[p][c];//q是链接点
        //2.链接点合法，从新点向q建链接边
        if(len[q]==len[p]+1) fa[np]=q;
        else
        {//3.链接点不合法，则裂开q点，重建两类边
            int nq=++tot;//nq是新链接点
            len[nq]=len[p]+1;
            //重建nq，q，nq的链接边
            fa[nq]=fa[q];
            fa[q]=nq;
            fa[np]=nq;
            //指向q的转移边改为指向边
            for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
            //q发出的转移边复制给nq
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
        }
    }
}
ll ans;
vector<int>g[N];
void dfs(int u)
{
    for(auto v:g[u])
    {
        dfs(v);
        cnt[u]+=cnt[v];
    }
    if(cnt[u]>1)
    {
        ans=max(ans,cnt[u]*len[u]);
    }
}
void solve()
{
    string s;
    cin>>s;
    for(auto i:s) extend(i-'a');
    for(int i=2;i<=tot;i++) g[fa[i]].push_back(i);
    dfs(1);
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
