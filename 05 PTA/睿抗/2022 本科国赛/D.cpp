#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1010][1010];
vector<int>a,b;
int op[1010][1010];
//11i
//22j
int fx(int i,int j)
{
	if(i==-1) return j+1;
	if(j==-1) return i+1;
	if(dp[i][j]!=-1) return dp[i][j];
	
	int mi=1e9;
	if(a[i]==b[j]) mi=min(mi,fx(i-1,j-1));
	else
	{
		mi=min(mi,fx(i,j-1)+1);//插入一个数等于b[j]
		mi=min(mi,fx(i-1,j)+1);//删除a[i]
		mi=min(mi,fx(i-1,j-1)+1);//替换
	}
	return dp[i][j]=mi;
}
void solve()
{
	while(1)
	{
		int x;
		cin>>x;
		if(x==-1) break;
		a.push_back(x);
	}
	while(1)
	{
		int x;
		cin>>x;
		if(x==-1) break;
		b.push_back(x);
	}

	

	int n=a.size();
	int m=b.size();
	for(int i=1;i<=n;i++) dp[i][0]=i;
	for(int j=1;j<=m;j++) dp[0][j]=j;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1]) 
			{
				dp[i][j]=dp[i-1][j-1];
				op[i][j]=2;//啥也不做
			}
			else 
			{
				dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
				if(dp[i][j]==dp[i-1][j]+1) op[i][j]=0;//删除a[i]
				else if(dp[i][j]==dp[i][j-1]+1) op[i][j]=3;//插入b[j]
				else op[i][j]=1;//a[i]变b[j]
			}
		}
	}

	int x=n,y=m;
	stack<int>st;
	while(x!=0||y!=0)
	{
		st.push(op[x][y]);
		if(op[x][y]==2) x--,y--;
		else if(op[x][y]==1) x--,y--;
		else if(op[x][y]==3) y--;
		else x--;

		if(!x)
		{
			int c=y;
			while(y--) st.push(3);
			break;
		}
		if(!y)
		{
			int c=x;
			while(x--) st.push(0);
			break;
		}
	}

	cout<<dp[n][m]<<"\n";
	while(!st.empty()) 
	{
		cout<<st.top();
		st.pop();
	}
	
	// for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=-1;
	// cout<<fx(n-1,m-1)<<"\n";
	//dp[i][j]：a的前i个匹配b的前j个的代价 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
