#include <bits/stdc++.h>
using namespace std;

string s[26][7];
string res[7];
void solve()
{
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<7;j++) cin>>s[i][j];
	}
	string a;
	cin>>a;
	a+='!';
	int p=0;
	vector<string>res;
	for(int i=0;i<a.size();i++)
	if(!isupper(a[i]))
	{
		res.push_back(a.substr(p,i-p));
		p=i+1;
	}
	for(auto i:res) 
	{
		for(int k=0;k<7;k++) res[k]="";
		cout<<i<<"\n";
		for(auto j:i)
		{
			for(int k=0;k<7;k++)
			res[k]+=s[j-'A'][k];
		}
		// for(int k=0;k<7;k++) cout<<res[k]<<"\n";
		// // cout<<i<<"\n";
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
