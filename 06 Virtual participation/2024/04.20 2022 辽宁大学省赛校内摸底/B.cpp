#include <bits/stdc++.h>
using namespace std;
int n,a[110];
void solve()
{
	cin>>n;
	map<int,int>c;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=0;i<=10;i++)
	{
		if(c[(1<<i)]>=2)
		{
			c[(1<<(i+1))]+=c[(1<<i)]/2;
			c[(1<<i)]%=2;
		}
	}
	//for(auto i:c) cout<<i.first<<" "<<i.second<<"\n";
	if(c[2048]>=1) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
