#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define P 1000000007
int n,f[N][4][4][2];
int dfs(int p,int p2,int p1,int fx)
{
	if(p==n) return fx;
	if(f[p][p2][p1][fx]) return f[p][p2][p1][fx];
	int res=0;
	for(int i=0;i<26;i++)
	{    
		if(p2==0&&p1==1&&i==2) continue;//der
		if(p2==2&&p1==1&&i==0) res=(res+dfs(p+1,p1,i,1))%P;
		else res=(res+dfs(p+1,p1,i>2? 3:i,fx))%P;
	}
	return f[p][p2][p1][fx]=res;
}
void solve()
{
	cin>>n;
	cout<<dfs(0,3,3,0)<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

