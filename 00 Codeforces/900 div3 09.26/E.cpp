#include <bits/stdc++.h>
using namespace std;
int a[200010][32],n,t,q,l,k,lf,r,m,res;
int ck(int x)
{
	int ans=0;
	for(int i=30;i>=0;i--)
	if(a[x][i]-a[l-1][i]==x-l+1) ans+=(1<<i);
	if(ans>=k) return 1;
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		for(int j=30;j>=0;j--) 
		if(t>>j&1) a[i][j]=a[i-1][j]+1;
		else a[i][j]=a[i-1][j];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>k;
		lf=l,r=n;
		res=0;
		while(lf<=r)
		{
			m=lf+r>>1;
			if(ck(m)) lf=m+1,res=max(res,m);
			else r=m-1;
		}
		if(res==0) res=-1; 
		cout<<res<<" ";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
