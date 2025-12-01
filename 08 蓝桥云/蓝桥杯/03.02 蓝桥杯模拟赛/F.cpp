#include<bits/stdc++.h>
using namespace std;
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	string s;
	s="ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";
	map<string,int>cnt;
	int mx=0;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i;j<s.size();j++)
		{
			string t="";
			for(int k=i;k<=j;k++) t+=s[k];
			cnt[t]++;
			mx=max(mx,cnt[t]);
		}
	}
	cout<<mx<<"\n";
//	for(auto i:cnt) cout<<i.first<<" "<<i.second<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
