#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,m,q,op[N];
int a[510][510];
int x[N];
int y[N];
int x1[N];
int x2[N];
int y11[N];
int y2[N];
int fa[510*510];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
}
// void print()
// {
// 	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<find((i-1)*m+j)<<" ";
// 	cout<<"\n";
// }
bool ck(int z)
{
	// cout<<z<<"???\n";
	z--;
	int x=z/m+1;
	int y=z%m+1;
	return a[x][y]==0;
}
void solve()
{
	cin>>n>>m>>q;
	
	for(int i=1;i<=n*m;i++) fa[i]=i;

	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='*') a[i][j]=1;
			else a[i][j]=0;
		}
	}

	for(int i=1;i<=q;i++)
	{
		cin>>op[i];
		if(op[i]==1) 
		{
			cin>>x[i]>>y[i];
			a[x[i]][y[i]]++;
		}
		else cin>>x1[i]>>y11[i]>>x2[i]>>y2[i];
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!a[i][j]&&j+1<=m&&!a[i][j+1]) merge((i-1)*m+j,(i-1)*m+j+1);
			if(!a[i][j]&&i+1<=n&&!a[i+1][j]) merge((i-1)*m+j,i*m+j);
		}
	}


	stack<char>st;
	for(int i=q;i>=1;i--)
	{
		if(op[i]==2)
		{
			int a=(x1[i]-1)*m+y11[i];
			int b=(x2[i]-1)*m+y2[i];
			// cout<<i<<" "<<a<<" "<<b<<"?\n";
			if(find(a)==find(b)&&ck(a)&&ck(b)) st.push('1');
			else st.push('0');
		}
		else
		{
			a[x[i]][y[i]]--;
			if(!a[x[i]][y[i]])
			for(int j=0;j<4;j++)
			{
				int nx=x[i]+dx[j];
				int ny=y[i]+dy[j];
				if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]) continue;
				merge((x[i]-1)*m+y[i],(nx-1)*m+ny);
			}
		}
		// print();
	}
	while(st.size())
	{
		if(st.top()=='1') cout<<"Yes\n";
		else cout<<"No\n";
		st.pop();
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}  
