#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int v[N],w[N];
int n,l,r,m;
int ck(int x)
{
	vector<int>w1,w2(n+1);	
	for(int i=1;i<=n;i++) 
	if(v[i]>=x) w2[i]=v[i]+w[i];
	else w1.push_back(w[i]);
	sort(w1.begin(),w1.end());
	sort(w2.begin(),w2.end());
	
	int j=w2.size()-1;
	for(int i=w1.size()-1;i>=0;i--)
	{
		if(w2[j]-w1[i]>=x) j--;
		else return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	l=0,r=1e9;
	while(l<=r)
	{
		//cout<<l<<" "<<r<<"\n";
		m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	}
	cout<<l-1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;
	cin>>T;
	while(T--) solve();
}
