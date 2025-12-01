#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],res,ans=1e18,pre[100010][2],suf[100010][2];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) res+=abs(a[i]-a[i-1]);
	for(int i=1;i<=n;i++)
    {
		int t=0,t1=0,t2=0;
		if(i+1<=n) t+=abs(a[i+1]-a[i]);
		if(i-1>=1) t+=abs(a[i]-a[i-1]);
		if(i+1<=n) t1+=abs(a[i+1]-a[i]/2*2);
		if(i-1>=1) t1+=abs(a[i]/2*2-a[i-1]);
		ans=min(ans,res-t+t1);
	}
	
	int t1=abs(a[2]-a[1])+abs(a[3]-a[2]);
	int t2=abs(2*a[2]-a[1]/2)+abs(a[3]-2*a[2]);
	int t3=abs(a[2]/2-a[1]*2)+abs(a[3]-a[2]/2);
	ans=min(ans,res-t1+t2);
	ans=min(ans,res-t1+t3);
    
	t1=abs(a[n]-a[n-1])+abs(a[n-1]-a[n-2]);
	t2=abs(2*a[n]-a[n-1]/2)+abs(a[n-1]/2-a[n-2]);
	t3=abs(a[n]/2-a[n-1]*2)+abs(a[n-1]*2-a[n-2]);
	ans=min(ans,res-t1+t2);
	ans=min(ans,res-t1+t3);
	
	for(int i=2;i<=n-2;i++)
	{
		t1=abs(a[i]-a[i-1])+abs(a[i+1]-a[i])+abs(a[i+2]-a[i+1]);
		t2=abs(a[i]*2-a[i-1])+abs(a[i+1]/2-a[i]*2)+abs(a[i+2]-a[i+1]/2);
		t3=abs(a[i]/2-a[i-1])+abs(a[i+1]*2-a[i]/2)+abs(a[i+2]-a[i+1]*2);
		ans=min(ans,res-t1+t2);
		ans=min(ans,res-t1+t3);
	}
	
    
    pre[1][0]=abs(a[2]-a[1])-abs(a[2]-a[1]*2);
    pre[1][1]=abs(a[2]-a[1])-abs(a[2]-a[1]/2);
	for(int i=2;i<=n;i++)
	{
		int t=0,t1=0,t2=0;
		if(i+1<=n) t+=abs(a[i+1]-a[i]);
		if(i-1>=1) t+=abs(a[i]-a[i-1]);
        
		if(i+1<=n) t1+=abs(a[i+1]-a[i]*2);
		if(i-1>=1) t1+=abs(a[i]*2-a[i-1]);
		if(i+1<=n) t2+=abs(a[i+1]-a[i]/2);
		if(i-1>=1) t2+=abs(a[i]/2-a[i-1]);
        pre[i][0]=max(pre[i-1][0],t-t1);
        pre[i][1]=max(pre[i-1][1],t-t2);
        
	}
    
    suf[n][0]=abs(a[n]-a[n-1])-abs(a[n]*2-a[n-1]);
    suf[n][1]=abs(a[n]-a[n-1])-abs(a[n]/2-a[n-1]);
	for(int i=n-1;i>=1;i--)
	{
		int t=0,t1=0,t2=0;
		if(i+1<=n) t+=abs(a[i+1]-a[i]);
		if(i-1>=1) t+=abs(a[i]-a[i-1]);
		if(i+1<=n) t1+=abs(a[i+1]-a[i]*2);
		if(i-1>=1) t1+=abs(a[i]*2-a[i-1]);
		if(i+1<=n) t2+=abs(a[i+1]-a[i]/2);
		if(i-1>=1) t2+=abs(a[i]/2-a[i-1]);
        suf[i][0]=max(suf[i+1][0],t-t1);
        suf[i][1]=max(suf[i+1][1],t-t2);
	}

	for(int i=2;i<=n-1;i++) 
	{
		ans=min(ans,res-pre[i-1][1]-suf[i+1][0]);
		ans=min(ans,res-pre[i-1][0]-suf[i+1][1]);
	}
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
