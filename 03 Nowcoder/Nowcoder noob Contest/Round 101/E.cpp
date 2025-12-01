#include <bits/stdc++.h>
using namespace std;
int n,t,vt[1000010];
void solve()
{
	set<int>a;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		a.insert(t);
	}
	
	vector<int>ans;
	for(int i=1;i<=1e6;i++)
	{
		if(vt[i]) continue;
		if(a.count(i)) ans.push_back(i);
		else for(int j=i+i;j<=1e6;j+=i) vt[j]=1;
	}
	cout<<ans.size()<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
