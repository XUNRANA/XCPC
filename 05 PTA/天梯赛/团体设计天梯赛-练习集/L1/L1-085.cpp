#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[7];
void solve()
{
	for(int i=1;i<=6;i++) cin>>a[i];
	cin>>n;
	for(int i=1;i<=6;i++)
	{
//		6 5 4 3 2
		if(a[i]>=6-n+1) a[i]=6-n+1-1;
		else a[i]=6-n+1;
	}
	int f=0;
	for(int i=1;i<=6;i++) 
	{
		if(f) cout<<" ";
		cout<<a[i];
		f=1;
	}
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

