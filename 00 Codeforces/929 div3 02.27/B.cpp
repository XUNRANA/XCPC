#include <bits/stdc++.h>
using namespace std;
int n,s,t1;
void solve()
{
	s=0;
	cin>>n;
	map<int,int>m;
	while(n--)
	{
		cin>>t1;
		m[t1%3]++;
		s+=t1;
	}
	if(s%3==0) cout<<0<<"\n";
	else if(s%3==2) cout<<1<<"\n";
	else if(s%3==1&&m[1]!=0) cout<<1<<"\n";
	else cout<<2<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
