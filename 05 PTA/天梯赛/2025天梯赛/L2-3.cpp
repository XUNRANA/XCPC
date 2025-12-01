#include <bits/stdc++.h>
using namespace std;
int cnt[25*3600];
int fx(string s)
{
	int res=0;
	res+=stoi(s.substr(0,2))*3600;
	res+=stoi(s.substr(3,2))*60;
	res+=stoi(s.substr(6,2));
	return res;
}
void solve()
{
	int n;
	cin>>n;
	vector<pair<string,string>>a;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		int c1=fx(x);
		int c2=fx(y);
		cnt[c1]++;
		cnt[c2+1]--;
	}
	int mx=cnt[1];
	for(int i=1;i<25*3600;i++) cnt[i]+=cnt[i-1],mx=max(mx,cnt[i]);
	cout<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
