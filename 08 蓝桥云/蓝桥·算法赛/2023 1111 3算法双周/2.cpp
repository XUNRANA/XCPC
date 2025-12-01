#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,w,c1,c2,c3,mx;
	cin>>n;
	long long ans=0;
	while(n--)
	{
		cin>>w;
		c1=c2=c3=0;
		if(w>=500) c1=w/10;
		if(w>=1000) 
		{
			c2=150;
			if(w==1111) c2=1111;
		}
		c3=w/20;
		mx=max(c1,max(c2,c3));
		ans+=w-mx;
	}
	cout<<ans;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
