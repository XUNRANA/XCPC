#include <bits/stdc++.h>
using namespace std;
#define N 100010
int f[N],n,m,v,w,s,q[N],g[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		memcpy(g,f,sizeof(f));//f备份到g 
		cin>>w>>v>>s;//价值、体积、数量 
		for(int j=0;j<v;j++)//拆分成v个类 
		{
			int h=0,t=-1;
			for(int k=j;k<=m;k+=v)//每个队使用单调队列 
			{
				//q[h]不在窗口[k-s*v,k-v]内，队头出队 
				if(h<=t&&q[h]<k-s*v) h++;
				//使用队头最大值更新f 
				if(h<=t) f[k]=max(g[k],g[q[h]]+(k-q[h])/v*w);
				//当前值比队尾更有价值，队尾出队 
				while(h<=t&&g[k]>=g[q[t]]+(k-q[t])/v*w) t--; 
				//下标入队，便于队头出队 
				q[++t]=k;
			}
		}
	} 
	cout<<f[m]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}


//二进制优化 
/*
#include <bits/stdc++.h>
using namespace std;
#define N 2010
int n,m,a,b,c,cnt=1,f[40010],w[N],v[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		for(int j=1;j<=c;j<<=1)
		{
			v[++cnt]=j*a,w[cnt]=j*b;
			c-=j;
		}
		if(c) v[++cnt]=a*c,w[cnt]=b*c;
	}
	for(int i=1;i<=cnt;i++)
	for(int j=m;j>=w[i];j--)
	f[j]=max(f[j],f[j-w[i]]+v[i]); 
	cout<<f[m]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
*/
