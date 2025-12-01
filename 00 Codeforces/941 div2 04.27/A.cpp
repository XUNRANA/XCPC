#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,ans,t;
	cin>>n>>k;
	map<int,int>m;
	ans=n;
	while(n--)
	{
		cin>>t;
		m[t]++;
	}
	for(int i=1;i<=100;i++) 
	if(m[i]>=k)
	{
		ans=k-1;
		break;
	}
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
