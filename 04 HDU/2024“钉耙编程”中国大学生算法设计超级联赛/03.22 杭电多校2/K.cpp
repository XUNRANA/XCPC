#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P1 13331
#define P 998244353
int pc[10010],p[10010];
int pb[100010];
int get(int l,int r,int t[])
{
    return (t[r]-t[l-1]*p[r-l+1]%P+P)%P;
}

struct Tree
{
    int fail;//失配指针
    int vis[26];//子节点位置
    int end;//标记几个单词以这个节点结尾
}AC[1000010];//Trie树
int cnt=0;//Trie的指针
int insert(string s)
{
    int u=0;//字典树根节点
    for(auto i:s)
    {
        int v=i-'a';
        if(!AC[u].vis[v]) AC[u].vis[v]=++cnt;
        u=AC[u].vis[v];
    }
    AC[u].end++;//结尾个数增加
    return u;
}
void get_fail()
{
    queue<int>q;
    for(int i=0;i<26;i++)//第二层处理
    {
        if(AC[0].vis[i])
        {
            AC[AC[0].vis[i]].fail=0;//指向根节点
            q.push(AC[0].vis[i]);//压入队列
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(AC[u].vis[i])
            {
                AC[AC[u].vis[i]].fail=AC[AC[u].fail].vis[i];
                q.push(AC[u].vis[i]);
            }
            else AC[u].vis[i]=AC[AC[u].fail].vis[i];
        }
    }
}
set<int>res;
int ac_query(string s)
{
    int u=0,ans=0;
    for(auto i:s)
    {
        int v=i-'a';
        u=AC[u].vis[v];
        for(int t=u;t&&AC[t].end!=-1;t=AC[t].fail)
        {
            res.insert(t);
            ans+=AC[t].end;
            AC[t].end=-1;
        }
    }
    return ans;
}

void solve()
{
    string a,c;
    int n;
    cin>>n;
    cin>>a>>c;
    int lc=c.size();
    c=" "+c;
    pc[0]=p[0]=1;
    for(int i=1;i<=lc;i++) 
    {
        pc[i]=(pc[i-1]*P1%P+c[i])%P;
        p[i]=p[i-1]*P1%P;
    }
    vector<int>idx(n+1,0);
    for(int i=1;i<=n;i++)
    {
        string b1,b2;
        cin>>b1>>b2;
        int lb=b2.size();
        b2=" "+b2;
        pb[0]=1;
        int f=0;
        for(int j=1;j<=lb;j++)
        {
            pb[j]=(pb[j-1]*P1%P+b2[j])%P;
            if(lb>=lc)
            {
                if(get(1,lc,pc)==get(j-lc+1,j,pb))
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==1) idx[i]=insert(b1);
    }
    
    res.clear();
    get_fail();
    ac_query(a);

    for(int i=1;i<=n;i++) if(idx[i]&&res.count(idx[i])) cout<<i<<" ";
    cout<<"\n";
    
    for(int i=0;i<=cnt;i++) 
    {
        AC[i].fail=AC[i].end=0;
        for(int j=0;j<26;j++) AC[i].vis[j]=0;
    }
    cnt=0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}