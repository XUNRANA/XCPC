#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct node
{
	int l,r,d;
}a[150100];
int dp[150100];
bool cmp(node a1,node a2)
{
	return a1.r<a2.r; 
}
int lower_bound(int l,int r,int key)
{
	int ans=0,m;
	while(l<=r)
	{
		m=l+r>>1;
		if(a[m].r<key) ans=m,l=m+1;
		else r=m-1;
	}
	return ans;
}
int main()
{
	/*
	1 3
	3 4
	7 8
	*/
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r,a[i].d=a[i].r-a[i].l+1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	dp[i]=max(dp[i-1],dp[lower_bound(1,i-1,a[i].l)]+a[i].r-a[i].l+1);
	cout<<dp[n];
}
