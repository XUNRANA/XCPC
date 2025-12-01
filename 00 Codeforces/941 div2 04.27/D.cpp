#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,k1,t,s=0;
	cin>>n>>k;
	for(int i=30;i>=0;i--)
	{
		if(k>>i&1)
		{
			k1=1<<i;
			break;
		}
	}
	t=1;
	vector<int>ans;
	while(1)
	{
		ans.push_back(t);
		s=t*2-1;
		if(s>=n) break;
		t*=2;
	}
	ans.push_back(k1*2+1);
	ans.push_back(k1-1);
	

	cout<<ans.size()-1<<"\n";
	for(auto i:ans) 
	{
		if(i==k1) continue;
		cout<<i<<" ";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
