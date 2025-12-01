#include <bits/stdc++.h>
using namespace std;
int n,x,ans;
int f(int x)
{
	int res=0;
	for(int i=30;i>=0;i--) 
	if(x>>i&1) ;
	else res+=1<<i;
	return res;  
}
void solve()
{
	ans=0;
	cin>>n;
	map<int,int>m;
	while(n--)
	{
		cin>>x;
		if(m[f(x)]>=1)//f()º¯Êýreturn xµÄÁíÒ»°ë 
		{
			m[f(x)]--;
			ans++;
		}
		else m[x]++;
	}
	for(auto i:m) if(i.second>=1) ans+=i.second;
	cout<<ans<<"\n";
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
