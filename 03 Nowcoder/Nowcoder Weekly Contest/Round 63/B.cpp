#include <bits/stdc++.h>
using namespace std;
int n,k,a[1010];
bool ck(deque<int>a)
{
	vector<int>b;
	for(auto i:a) b.push_back(i);
	int cnt=0;
	for(int i=0;i<b.size();i++) if(b[i]!=b[b.size()-1-i]) cnt++;
	return cnt==2;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<deque<int>>res;
	deque<int>dq;
	for(int i=1;i<=n;i++)
	{
		dq.push_back(a[i]);
		if(dq.size()==k)
		{
			res.push_back(dq);
			dq.pop_front();
		}
	}
	int ans=0;
	for(auto i:res)
	{
		if(ck(i)) ans++;
//		for(auto j:i) cout<<j<<" ";
//		cout<<"\n";
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
