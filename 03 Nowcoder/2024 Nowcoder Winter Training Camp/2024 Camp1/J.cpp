#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,t,l,r,m;
vector<int>a;
bool ck(int d)
{ 
	int lst=y;//lst相当于每一轮不动的点 
	set<int>s;
	if(abs(x-y)<=d) s.insert(x);
	for(auto x:a)
	{
		if(!s.empty()&&abs(x-lst)<=d) s.insert(lst);
		while(!s.empty()&&*s.begin()<x-d) s.erase(s.begin());
		while(!s.empty()&&*s.rbegin()>x+d) s.erase(*s.rbegin());
		lst=x;
	}
	return !s.empty();
} 
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a.push_back(t);
	}
	l=0,r=1e9;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
