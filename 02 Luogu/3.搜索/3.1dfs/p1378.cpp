#include <bits/stdc++.h>
using namespace std;
double PI=3.1415926535;
int n,f[10];
double ansmax,x[10],y[10],r[10],x1,y11,x2,y2;
double fx(int i)
{
	double s1=min(abs(x[i]-x1),abs(x[i]-x2));
	double s2=min(abs(y[i]-y11),abs(y[i]-y2));
	double ans=min(s1,s2);
	for(int j=1;j<=n;j++)
	if(i!=j&&f[j])
	{
		double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		ans=min(ans,max(d-r[j],0.0));
	}
	return ans;
}
void dfs(int k,double s)
{
	if(k>n) 
	{
		ansmax=max(ansmax,s);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			r[i]=fx(i);
			f[i]=1;
			dfs(k+1,s+r[i]*r[i]*PI);
			f[i]=0;
		}
	}
}
int main()
{
	cin>>n>>x1>>y11>>x2>>y2;
	double ss=abs(x2-x1)*abs(y2-y11);
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	dfs(1,0);
	cout<<int(ss-ansmax+0.5);
} 
