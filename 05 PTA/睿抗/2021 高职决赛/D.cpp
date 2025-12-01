#include <bits/stdc++.h>
using namespace std;

int a[11][11];
int vt[11];
int st[15];

int f_ans[15];
int ans[15];
int cnt;
int n,m;
int l;
//别用vector
void dfs()
{
	int nst[15];
	for(int i=0;i<m;i++)
	{
		if(vt[i]) continue;
		for(int j=0;j<n;j++) nst[j]=st[j];
		
		int f=1;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=0) st[j]=a[i][j];
			if(st[j]!=1) f=0;
		}
		
		if(f)
		{
		
			f_ans[cnt++]=i;

			if(!l||l>cnt)
			{
				l=cnt;
				for(int j=0;j<=cnt;j++) ans[j]=f_ans[j];
			}
			cnt--;
			return ;
		}
		else
		{
			vt[i]=1;
			f_ans[cnt++]=i;
			dfs();
			cnt--;
			vt[i]=0;
		}
		
		for(int j=0;j<n;j++) st[j]=nst[j];
		
	}
}

void solve()
{
	cin>>n>>m;
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];	
	for(int i=0;i<n;i++) st[i]=-1;
	dfs();
	for(int i=0;i<l;i++)
	{
		if(i) cout<<" ";
		cout<<ans[i]+1;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
