#include <bits/stdc++.h>
using namespace std;
int n,ans,t;
void solve()
{
	cin>>n;
	ans=0;
	vector<int>c(110);
	while(n--)
	{
		cin>>t;
		c[t]++;
	}
	for(int i=1;i<=100;i++) if(c[i]>=3) ans+=c[i]/3;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
