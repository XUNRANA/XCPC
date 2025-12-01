#include <bits/stdc++.h>
using namespace std;
int a,b,n,m,h;
bool ck(int x)
{
	int y=n%b+m-x;
	return y/b*(h-b)>=x;	
}
void solve()
{
	
	cin>>a>>b>>n>>m>>h;
	int k=n/b*(h-a);
	if(k>=m-1) cout<<n+1<<"\n";
	else
	{ 
		m-=k;
		int l=0,r=m-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(ck(mid)) l=mid+1;
			else r=mid-1;
		}
		cout<<n+m-l+1<<"\n";
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
