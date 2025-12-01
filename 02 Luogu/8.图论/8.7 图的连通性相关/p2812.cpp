#include  <bits/stdc++.h>
using namespace std;
#define N 10010
vector<int>g[N];
int dfn[N],low[N],tot,stk[N],instk[N],top,scc[N],siz[N],cnt;
int din[N],dout[N];
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		while(cin>>x,x) g[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
	if(!dfn[i]) tarjan(i);
	
	for(int i=1;i<=n;i++)
	{
		for(auto j:g[i])
		{
			if(scc[j]!=scc[i])
			{
				dout[scc[i]]++;//出度 
				din[scc[j]]++;//入度 
			}
		}
	}
	int a=0,b=0;
	for(int i=1;i<=cnt;i++)
	{
		if(!din[i]) a++;
		if(!dout[i]) b++;
	}
	cout<<a<<"\n";//入度为0的个数 
	if(cnt==1) cout<<"0\n";//特判 
	else cout<<max(a,b)<<"\n";//入度，出度取max 
}
