#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,x,y,p[200010],ans,last,t,l,r;
void solve()
{
	cin>>n>>m>>x>>y;
	p[0]=0;
	for(int i=1;i<=m;i++) cin>>p[i];
	p[m+1]=n+1;
	ans=0;
	last=x;
	for(int i=1;i<=m+1;i++)
	{
		
		l=p[i-1]+1,r=p[i]-1;
		ans+=(r-l+1)/(y+2)*2;
		t=(r-l+1)%(y+2);
		/*
		cout<<l<<" "<<r<<"\n";
		cout<<(r-l+1)/(y+2)*2<<" "<<(r-l+1)%(y+2)<<"\n";
		*/
		if(t>last)
		{
			t-=last;
			ans++,t--;
		}
		last=min(x,y-t);//上一次连续工作天数 
		//cout<<last<<"\n";
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve();
} 
