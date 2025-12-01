#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,b,x,y;
void solve()
{
	cin>>n>>k>>b;
	vector<int>v[3];
	for(int i=1;i<=2*n;i++)
	{
		cin>>x>>y;
		if(k*x+b==y) v[0].push_back(i);
		else if(k*x+b>y) v[1].push_back(i);
		else v[2].push_back(i);
	}
	vector< pair<pair<int,int>,int> >ans;
	if(v[1].size()>v[2].size()) swap(v[1],v[2]);
	int a0=v[0].size(),a1=v[1].size(),a2=v[2].size();
	for(int i=0;i<a1;i++) ans.push_back({{v[1][i],v[2][i]},1});
	int i,k;
	for(i=a1,k=0;i<a2&&k<a0;i++,k++)
	{
		ans.push_back({{v[2][i],v[0][k]},1});
	}
	while(k<a0) ans.push_back({{v[0][k],v[0][k+1]},1}),k+=2;
	cout<<ans.size()<<"\n";
	while(i<a2) ans.push_back({{v[2][i],v[2][i+1]},0}),i+=2;
	for(auto i:ans)
	{
		cout<<i.first.first<<" "<<i.first.second<<" ";
		if(i.second) cout<<"Y\n";
		else cout<<"N\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
