#include <bits/stdc++.h>
using namespace std;
long long a,b,r,t,ans;
int f[65];
void solve()
{
	cin>>a>>b>>r;
	for(int i=0;i<65;i++) f[i]=0;
	for(int i=63;i>=0;i--) f[i]=(a>>i&1)-(b>>i&1);
	int f1=0,f2=0;
	ans=0;
	for(int i=63;i>=0;i--)
	if(f[i]!=0) 
    {
    	if(f1==0) 
    	{
    		ans=1ll<<i;
    		if(f[i]==1) f2=1;
    		f1=1;
		}
		else if(f2==1)
		{
			if(f[i]==-1) ans-=1ll<<i;
			if(f[i]==1) 
			{
				if(1ll<<i <=r) ans-=1ll<<i,r-=1ll<<i;
				else ans+=1ll<<i;
			}
		}
		else
		{
			if(f[i]==1) ans-=1ll<<i;
			if(f[i]==-1) 
			{
				if(1ll<<i <=r) ans-=1ll<<i,r-=1ll<<i;
				else ans+=1ll<<i;
			}
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
}
