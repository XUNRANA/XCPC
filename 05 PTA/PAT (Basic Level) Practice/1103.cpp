#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
void init()
{
	for(int i=1;i<=100000;i++) 
	{
		mp[i*i+(i-1)*(i-1)]=i;
	}
}
int is(int x)
{
	int y=sqrtl(x);
	if(y*y==x)
	{
		if(mp.count(y)) 
		{
			return mp[y];
		}
		return 0;
	}
	return 0;
}
void solve()
{
	int l,r;
	cin>>l>>r;
	int f=0;
	l=max(l,2ll);
	for(int a=l;a<=r;a++)
	{
		int x=a*a*a-(a-1)*(a-1)*(a-1);
		if(is(x)) 
		{
			cout<<a<<" "<<is(x)<<"\n";
			f=1;
		}
	}
	if(!f) cout<<"No Solution\n";
}

signed main() 
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
