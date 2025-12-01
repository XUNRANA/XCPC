#include  <bits/stdc++.h>
using namespace std;
#define N 10010
vector<int>g[N];
int dfn[N],low[N],tot,stk[N],instk[N],top,scc[N],siz[N],cnt;
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
		do
		{
			y=stk[top--];
		//	cout<<y<<" ";
			instk[y]=0;//出栈 
			scc[y]=cnt;//SCC编号 
			siz[cnt]++;//SCC大小 
		}while(y!=x);
		//cout<<"\n";
	} 
}
int main()
{
	int n,m,ans;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	if(!dfn[i]) tarjan(i);
	ans=0;
	for(int i=1;i<=cnt;i++)
	if(siz[i]>1) ans++;
	cout<<ans<<"\n";
}
