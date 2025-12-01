#include <bits/stdc++.h>
using namespace std;

int n,a[2010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	map<int,pair<int,int>>mp;
	int mi=1e9; 
	for(int i=1;i<=n;i++)
	{
		vector<int>s;
		s.push_back(a[i]);
		for(int j=i;j<=n;j++)
		{
			auto it=lower_bound(s.begin(),s.end(),a[j]);
			s.insert(it,a[j]);
			int x=lower_bound(s.begin(),s.end(),a[i])-s.begin();
			int y=s.end()-upper_bound(s.begin(),s.end(),a[i]);
			mi=min(mi,-x+y);
			mp[-x+y]={i,j};
		}
	}
	cout<<mp[mi].first<<" "<<mp[mi].second<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
