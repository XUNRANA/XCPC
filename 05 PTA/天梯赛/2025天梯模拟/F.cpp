#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[10000010];
void solve()
{
	int n;
	cin>>n;
	int f=0;
	for(int j=(2*n+1)*n;j<=(2*n+1)*n+n;j++) 
	{
		if(f) cout<<"^2 + ";
		cout<<j;
		f=1;
	}
	cout<<"^2 =\n";
	
	f=0;
	for(int j=(2*n+1)*n+n+1;j<=(2*n+1)*n+2*n;j++) 
	{
		if(f) cout<<"^2 + ";
		cout<<j;
		f=1;
	}
	cout<<"^2\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
