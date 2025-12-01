#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	cin>>n>>k;
	int l=(1+n-1)*(n-1)/2;
	if(k<=l)
	{
		int l=1,r=n-1;
		while(l<=r)
		{
			int m=l+r>>1;
			if((1+m)*m/2>=k) r=m-1;
			else l=m+1;
		}
		int x=1,y=l;
		int t=k-(l)*(l-1)/2-1;
		while(t--)
		{
			x++;
			y--;
		}
		cout<<x<<" "<<y<<"\n";
	}
	else if(k<=l+n) 
	{
		int t=k-l-1;
		int x=1,y=n;
		while(t--)
		{
			x++;
			y--;
		}
		cout<<x<<" "<<y<<"\n";
	}
	else 
	{
		k=k-l-n;
		int l=1,r=n-1;
		while(l<=r)
		{
			int m=l+r>>1;
			if((m+n-1)*(n-1-m+1)/2>=k) l=m+1;
			else r=m-1;
		}
		l--;
		k-=(n-1+l+1)*(n-l-1)/2+1;
		int x=n+1-l,y=n;
		while(k--)
		{
			x++;
			y--;
		}
		cout<<x<<" "<<y<<"\n";
	}

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
