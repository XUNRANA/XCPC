#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[300010],lf,r,m,l[300010],s[300010],ans1[300010],ans2[300010];
int ck(int x,int i)
{
	if(x<1||x>l[i-1]) return 0;
	if(s[i-1]-s[x-1]>a[i]) return 1;
	return 0;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],ans1[i]=ans2[i]=1e9,s[i]=l[i]=0;
	for(int i=1;i<=n;i++) 
	{
		s[i]=s[i-1]+a[i];
		if(a[i]==a[i-1]) l[i]=l[i-1]; 
		else l[i]=i-1;
    }
	   
    for(int i=1;i<=n;i++)
    {
    	if(a[i]<a[i-1]) 
		{
			ans1[i]=1;
			continue;
		}
    	lf=1,r=l[i-1];//[1,l[i-1]]
    	while(lf<=r)
    	{
    		m=lf+r>>1;
    		if(ck(m,i)) lf=m+1;
    		else r=m-1;
		}
		if(ck(lf,i)) ans1[i]=min(ans1[i],i-lf);
		if(ck(lf+1,i)) ans1[i]=min(ans1[i],i-lf-1);
		if(ck(lf-1,i)) ans1[i]=min(ans1[i],i-lf+1);
	}
	
	
	for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for(int i=1;i<=n;i++) s[i]=l[i]=0;
	for(int i=1;i<=n;i++) 
	{
		s[i]=s[i-1]+a[i];
		if(a[i]==a[i-1]) l[i]=l[i-1]; 
		else l[i]=i-1;
    }
    for(int i=1;i<=n;i++)
    {
    	if(a[i]<a[i-1]) 
		{
			ans2[i]=1;
			continue;
		}
    	lf=1,r=l[i-1];//[1,l[i-1]]
    	while(lf<=r)
    	{
    		m=lf+r>>1;
    		if(ck(m,i)) lf=m+1;
    		else r=m-1;
		}
		if(ck(lf,i)) ans2[i]=min(ans2[i],i-lf);
		if(ck(lf+1,i)) ans2[i]=min(ans2[i],i-lf-1);
		if(ck(lf-1,i)) ans2[i]=min(ans2[i],i-lf+1);
	}
	
	
	for(int i=1;i<=n;i++)
	{
		if(min(ans1[i],ans2[n-i+1])==1e9) cout<<"-1 ";
		else cout<<min(ans1[i],ans2[n-i+1])<<" ";
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
