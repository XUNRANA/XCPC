#include <bits/stdc++.h>
using namespace std;
int n,k,a[25],cnt=0;
int is(int n)
{
	if(n<2) return 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
void dfs(int m,int sum,int s)
{
	if(m==k&&is(sum)) 
	{
		cnt++;
		return ;
	}
	for(int i=s;i<=n;i++) dfs(m+1,sum+a[i],i+1);
	return ; 
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,1);
	cout<<cnt;
}
