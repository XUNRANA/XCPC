#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s,t="",k;
	cin>>s>>k;
	int c;
	if(k.size()>3) c=26;
	else c=min(stoll(k),26ll);
	while(c--) t+=s;
	vector<char>a;
	for(auto i:t)
	{
		auto it=lower_bound(a.begin(),a.end(),i);
		if(it==a.end()) a.push_back(i);
		else *it=i;
	}
	cout<<a.size()<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

