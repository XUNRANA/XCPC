#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[60];
void solve()
{
	int n;
	cin>>n;
	vector<string>a,b;
	map<string,string>mp;
	for(int i=1;i<=n;i++) 
	{
		int x;
		string s1;
		cin>>x>>s1;
		s[i]=s1;
		if(x) a.push_back(s1);
		else b.push_back(s1);
	}
	int j=b.size()-1;
	for(int i=0;i<a.size();i++,j--)
	{
		mp[b[j]]=a[i];
		mp[a[i]]=b[j];
	}
	for(int i=1;i<=n/2;i++) cout<<s[i]<<" "<<mp[s[i]]<<"\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

