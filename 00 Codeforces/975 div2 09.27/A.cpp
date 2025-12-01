#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,t;
	cin>>n;
	vector<int>a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(i&1) a.push_back(t);
		else b.push_back(t);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(n==1) 
	{
		cout<<t+1<<"\n";
		return ;
	}
	cout<<max(a.back()+(int)a.size(),b.back()+(int)b.size())<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
