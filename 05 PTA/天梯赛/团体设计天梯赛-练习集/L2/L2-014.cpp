#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,x;
	vector<int>a;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		auto it=lower_bound(a.begin(),a.end(),x);
		if(it==a.end()) a.push_back(x);
		else *it=x;
	}
	cout<<a.size()<<"\n";
	
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

