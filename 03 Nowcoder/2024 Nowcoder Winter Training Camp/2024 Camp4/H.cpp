#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,d1[3010][3010],d2[3010][3010],tr[3010];
char s[3010][3010];
vector<int>ve[6010];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=m)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
    if(i<=0) return 0;//注意可能小于0 
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}

void fx(int h,int l,int r)
{
	int mx=0,i;
	for(i=l;i<=r;i+=2)//处理奇数列 
	{
		int L=i,R=L+d1[h][i]*2-2;//以这个点为左下角，找可能达到的右下角 
		mx=max(mx,R);//找最右端，以防撤销不到 
		ve[R].push_back(L);//方便撤销 
		add(i,1);
		R=i;
		L=R-(d2[h][i]*2-2);//以这个点为右下角，求最小的产生贡献左下角 
		ans+=query(i)-query(L-1);//满足条件的左端点 
		
		for(auto &j:ve[i])//撤销 
		add(j,-1);
		ve[i].clear();
	}
	for(;i<=mx;i+=2)//接着撤销 
	{
		for(auto &j:ve[i]) 
		add(j,-1);
		ve[i].clear();
	}
	
	mx=0;
	for(i=l+1;i<=r;i+=2)//处理偶数列 
	{
		int L=i,R=L+d1[h][i]*2-2;//以这个点为左下角，找可能达到的右下角 
		mx=max(mx,R);//找最右端，以防撤销不到 
		ve[R].push_back(L);//方便撤销 
		add(i,1);
		R=i;
		L=R-(d2[h][i]*2-2);//以这个点为右下角，求最小的产生贡献左下角 
		ans+=query(i)-query(L-1);//满足条件的左端点 
		
		for(auto &j:ve[i])//撤销 
		add(j,-1);
		ve[i].clear();
	}
	for(;i<=mx;i+=2)//接着撤销 
	{
		for(auto &j:ve[i]) 
		add(j,-1);
		ve[i].clear();
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>s[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*')
			{
				d1[i][j]=d1[i-1][j+1]+1;
				d2[i][j]=d2[i-1][j-1]+1;
			} 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='.') continue;
			int k=j;
			while(k+1<=m&&s[i][k+1]=='*') k++;
			fx(i,j,k);
			j=k;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='*') ans--;
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

/*
6 11
.....*.....
....*.*....
...*...*...
..*******..
.*..**...*.
***********
*/
