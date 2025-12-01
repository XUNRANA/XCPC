#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	if(k%2==0||k==n) cout<<"Yes\n";
	else 
	{
		
		int c=n/k;
			
		int c0=min(n%k,k/2);//最多0的个数
		 
		int c1=n%k-c0;//最少1的个数 
		
//		1的个数小于等于(n+1)/2 
		if((k+1)/2*c+c1<=(n+1)/2) cout<<"Yes\n";
		else cout<<"No\n"; 		
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
