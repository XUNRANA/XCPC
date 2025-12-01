#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n0,n1,n,d=1e9,a,b;
	cin>>n0>>n1>>n;
	for(int i=1;i<n;i++)
	{
		int j=n-i;
		if(n0%i||n1%j||n0/i==1||n1/j==1) continue;
		if(abs(n0/i-n1/j)<d)
		{
			d=abs(n0/i-n1/j);
			a=i;
			b=j;
		}
	}
	
	if(d==1e9) cout<<"No Solution\n";
	else cout<<a<<" "<<b<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

