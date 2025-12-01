#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m;
	cin>>n>>m;
	cin.ignore();
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		if(s.find("qiandao")!=s.npos||s.find("easy")!=s.npos) continue;
		cnt++;
		if(cnt==m+1) 
		{
			cout<<s<<"\n";
			return ;
		}
	}
	cout<<"Wo AK le\n";
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

