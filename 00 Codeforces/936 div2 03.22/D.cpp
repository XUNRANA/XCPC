#include <bits/stdc++.h>
using namespace std;
int n,x,ans,t,fx,cnt,a[100010],f[100010];
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=1;
	ans=-1;
	for(int j=30;j>=0;j--)
	{
		cnt=0;
		if(x&(1<<j))
		{
			fx=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]&(1<<j)) fx=!fx;
				if(fx&&f[i]) cnt++;
			}
			if(fx) ans=max(ans,cnt);//保证这一位是0、后面的随意 
		}
		else
		{
			fx=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]&(1<<j)) fx=!fx;
				if(!fx) f[i]=0;//这些位一定不能划分 
			}
			if(!fx)//这一位如果不能是0、直接输出了 
			{
				cout<<ans<<"\n";
				return ;
			}
		}
	}
	t=0;
	for(int i=1;i<=n;i++) if(f[i]) t++;
	cout<<max(t,ans)<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
