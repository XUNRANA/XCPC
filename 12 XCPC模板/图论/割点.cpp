#include  <bits/stdc++.h>
using namespace std;
#define N 20010
vector<int>g[N];
int dfn[N],low[N],tot,cut[N],root;
void tarjan(int x)
{
	//入x时，盖戳，入栈 
	dfn[x]=low[x]=++tot;
	int child=0; 
	for(auto y:g[x])
	{
		if(!dfn[y])//若y尚未访问 
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);//回x时更新low 
			if(low[y]>=dfn[x])//判割点 
			{
				child++;
				if(x!=root||child>1) cut[x]=1;//根结点两棵子树 
			}
		}
		else  //y已访问 
		low[x]=min(low[x],dfn[y]);//更新low 
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,x,y,cnt;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			root=i;
			tarjan(i);			
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++) if(cut[i]) cnt++;
	cout<<cnt<<"\n";
	for(int i=1;i<=n;i++) if(cut[i]) cout<<i<<" ";
	cout<<"\n";  
}