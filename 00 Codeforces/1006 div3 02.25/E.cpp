#include <bits/stdc++.h>
using namespace std;
vector<int>a;
void init()
{
	int s=0;
	for(int i=1;i<=499;i++) 
	{
		s+=i;
		a.push_back(s);
	}
}
vector<pair<int,int>>ans;
int i=0,j=0;
void f(int x)
{
	ans.push_back({i++,j});
	int c=1;
	while(x)
	{
		ans.push_back({i++,j});
		x-=c;
		c++;
	}
	j++;
}
void solve()
{
	int k;
	cin>>k;
	ans.clear();
	while(k)
	{
		auto it=upper_bound(a.begin(),a.end(),k);
		it--;
		f(*it);
		k-=*it;
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}
int main()
{
	init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
