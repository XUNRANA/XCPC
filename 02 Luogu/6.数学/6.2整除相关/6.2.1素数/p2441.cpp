#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	return y==0? x:gcd(y,x%y);
}
int a[200001];
int f[200001];
int dfs(int x,int y)
{
	if(x==0) return -1;//Ã»ÓÐ¸¸Ç×
	if(gcd(a[x],a[y])>1) return x;
	return dfs(f[x],y); 
}
int main()
{
	int n,k,x,y,t;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		f[y]=x;
	}
	while(k--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>y;
			cout<<dfs(f[y],y)<<endl;
		}
		else
		{
			cin>>x>>y;
			a[x]=y;
		} 
	}
}
