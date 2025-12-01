#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	cin.ignore();
	vector<pair<string,string>>vt; 
	for(int i=1;i<=n;i++)
	{
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		vt.push_back({s1,s3});
	}
	sort(vt.begin(),vt.end());
	string pre="00:00:00";
	string end="23:59:59";
	for(auto i:vt)
	{
		if(i.first!=pre) cout<<pre<<" - "<<i.first<<"\n";
		pre=i.second;
	}
	if(pre!=end) cout<<pre<<" - "<<end<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

