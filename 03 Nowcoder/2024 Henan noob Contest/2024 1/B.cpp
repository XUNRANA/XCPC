#include  <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],vt[N],in[N],out[N];
vector<int>g[N],g1[N];
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
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int n,y;
	cin>>n;
    int ans=0;
	for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        g[i].push_back(a[i]);
	}
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    
    for(int i=1;i<=n;i++) 
    if(scc[i]!=scc[a[i]])
    {
        g1[scc[i]].push_back(scc[a[i]]);
        in[scc[a[i]]]++;
    }

    vector<int>dp(cnt+1);
    queue<int>q;
    for(int i=1;i<=cnt;i++) 
    {
        dp[i]=siz[i];
        if(!in[i]) q.push(i);
    }
    
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto i:g1[x])
        {
            dp[i]=max(dp[i],siz[i]+dp[x]); 
            in[i]--;
            if(!in[i]) q.push(i);
        }
    }
    
    for(int i=1;i<=cnt;i++) ans=max(ans,dp[i]);
    cout<<ans<<"\n";
}
/*
10
2 3 4 5 1 1 2 3 4 5
*/


/*
#include  <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],vt[N],n,ans; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(!vt[i])
		{
			int t=i,cnt=0;
			while(vt[t]!=i)
			{
				vt[t]=i;
				t=a[t];
				cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans<<"\n";
}
*/ 
