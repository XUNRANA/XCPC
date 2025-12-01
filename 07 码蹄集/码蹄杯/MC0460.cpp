#include  <bits/stdc++.h>
using namespace std;
#define N 200010

struct node
{
    int c2,c3;
    int st;
}b[N],f[N];
int p[]={5,7,11,13,17,19};
node calc(int x)
{
    int c2=0,c3=0,st=0;
    while(x%2==0) c2++,x/=2;
    while(x%3==0) c3++,x/=3;
    for(int i=0;i<6;i++) if(x==p[i]) st|=1<<i;
    return (node){c2,c3,st};
}
int fcalc(int c2,int c3,int st)
{
    int res=1;
    while(c2--) res*=2;
    while(c3--) res*=3;
    for(int i=0;i<6;i++) if(st>>i&1) res*=p[i];
    return res;
}
int a[N];
bool dp[N][5][3][1<<6];

vector<int>g[N];
vector<int>mp[N];
int incnt[N];//缩点后的入度
int dfn[N],low[N],tot,stk[N],instk[N],top,scc[N],siz[N],cnt;
void tarjanInit(int n)
{
    for(int i=0;i<=n;i++) dfn[i]=low[i]=stk[i]=instk[i]=scc[i]=siz[i]=incnt[i]=0;
    tot=cnt=top=0;
}
void tarjan(int x)
{
	//入x时，盖戳，入栈 
	dfn[x]=low[x]=++tot;
	stk[++top]=x,instk[x]=1;
	for(auto y:g[x])
	{
		if(!dfn[y])//若y尚未访问 
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);//回x时更新low 
		}
		else if(instk[y]) //已访问且在栈中 
		low[x]=min(low[x],dfn[y]);//更新low 
	}
	//离x时，记录scc
	if(dfn[x]==low[x])//若x是scc的根 
	{
		int y;
		cnt++;
		//cout<<cnt<<":";
        int c2=0,c3=0,st=0;
		do
		{
			y=stk[top--];
            c2=max(c2,b[y].c2);
            c3=max(c3,b[y].c3);
            st|=b[y].st;
		//	cout<<y<<" ";
			instk[y]=0;//出栈 
			scc[y]=cnt;//SCC编号 
			siz[cnt]++;//SCC大小 
		}while(y!=x);
        f[cnt]=(node){c2,c3,st};
		//cout<<"\n";
	} 
}

void dpInit()
{
    for(int i=1;i<=cnt;i++)
    {
        for(int c2=0;c2<5;c2++)
        {
            for(int c3=0;c3<3;c3++)
            {
                for(int st=0;st<(1<<6);st++)
                dp[i][c2][c3][st]=0;
            }
        }
    }
}
void calcdp(int s)
{
    queue<int>q;
    q.push(s);
    dp[s][f[s].c2][f[s].c3][f[s].st]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int x=0;x<5;x++)
        {
            for(int y=0;y<3;y++)
            {
                for(int z=0;z<(1<<6);z++)
                {
                    if(!dp[u][x][y][z]) continue;

                    for(auto v:mp[u]) dp[v][max(x,f[v].c2)][max(y,f[v].c3)][z|f[v].st]=1;
                }
            }
        }
        for(auto v:mp[u]) 
        {
            incnt[v]--;
            if(incnt[v]==0) q.push(v);
        }
    }
}



void solve()
{
    int n,m,s;
    cin>>n>>m>>s;
	for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        b[i]=calc(a[i]);
        g[i].clear();//初始图
        mp[i].clear();//缩点后的图
    }
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
    tarjanInit(n);
    tarjan(s);
	for(int u=1;u<=n;u++)
    {
        if(!dfn[u]) continue;
        for(auto v:g[u])
        {
            if(scc[v]==scc[u]) continue;
            incnt[scc[v]]++;
            mp[scc[u]].push_back(scc[v]);
        }
    }

    dpInit();
    calcdp(scc[s]); 
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0) 
        {
            cout<<"-1 ";
            continue;
        }

        int ans=0;
        for(int c2=0;c2<5;c2++)
        {
            for(int c3=0;c3<3;c3++)
            {
                for(int st=0;st<(1<<6);st++)
                {
                    if(dp[scc[i]][c2][c3][st])
                    {
                        ans=max(ans,fcalc(c2,c3,st));
                    }
                }
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}