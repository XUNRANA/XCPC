#include <bits/stdc++.h>
using namespace std;
long long n,x,y,B;
void solve()
{
	cin>>n>>B>>x>>y;
	long long s=0,a=0;
	for(int i=1;i<=n;i++)
	{
		if(a+x>B) a-=y,s+=-y*(n-i+1);
		else a+=x,s+=x*(n-i+1);
	}
	cout<<s<<"\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

