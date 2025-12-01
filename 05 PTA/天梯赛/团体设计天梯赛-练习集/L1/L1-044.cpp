#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int k,cnt=0;
	cin>>k;
	map<string,string>win; 
	win["ChuiZi"]="Bu";
	win["Bu"]="JianDao";
	win["JianDao"]="ChuiZi";
	while(1)
	{
		cnt++;
		string s;
		cin>>s;
		if(s=="End") break;
		if(cnt%(k+1)==0) cout<<s<<"\n";
		else cout<<win[s]<<"\n";
	}
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

