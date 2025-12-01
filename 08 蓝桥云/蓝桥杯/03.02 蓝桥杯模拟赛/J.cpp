#include<bits/stdc++.h>
using namespace std;

string s[5];
void solve()
{
	vector<int>a;
	for(int i=1;i<=4;i++) 
	{
		cin>>s[i];
		a.push_back(i);
	}
	string ans="";
	do{
		string p="";
		for(auto i:a) p+=s[i];
		if(ans=="") ans=p;
		else ans=min(ans,p);
	}while(next_permutation(a.begin(),a.end()));

	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
