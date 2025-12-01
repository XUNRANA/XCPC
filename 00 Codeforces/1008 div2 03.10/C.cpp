#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[400010];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++) cin>>a[i];
	if(n==1) 
	{
		cout<<a[1]<<" "<<a[1]+a[2]<<" "<<a[2]<<"\n";
	}
	else 
	{	
		sort(a+1,a+1+2*n);
		vector<int>c,d;
		int sc=0,sd=0;
		for(int i=1;i<=2*n;i++)
		if(i<n) c.push_back(a[i]),sc+=a[i];
		else d.push_back(a[i]),sd+=a[i];
		
		c.push_back(sd-sc);
		cout<<d.back()<<" ";
		for(int i=0;i<n;i++) cout<<c[i]<<" "<<d[i]<<" ";
		cout<<"\n";
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

