#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	int s=0;
	vector<array<int,2>>a;
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		a.push_back({x,i});
	}
	sort(a.begin(),a.end(),greater<array<int,2>>());
	vector<int>ans;
	for(auto i:a)
	{
		s+=i[0];
		ans.push_back(i[1]);
		if(s>m)
		{
			cout<<ans.size()<<"\n";
			int f=0;
			for(auto j:ans) 
			{
				if(f) cout<<" ";
				cout<<j;
				f=1;
			}
			cout<<"\n";
			return ;
		}
	}
	cout<<"0\nSuan4 le ba, hai2 cha4 "<<m-s<<".\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
