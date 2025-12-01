#include <bits/stdc++.h>
using namespace std;
int n,l,r,a[100010];
void solve()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>p,s;
	for(int i=1;i<=r;i++) p.push_back(a[i]);
	for(int i=l;i<=n;i++) s.push_back(a[i]);
	sort(p.begin(),p.end());
	sort(s.begin(),s.end());
	long long ans1=0,ans2=0;
	for(int i=0;i<r-l+1;i++) ans1+=p[i],ans2+=s[i];
	cout<<min(ans1,ans2)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
