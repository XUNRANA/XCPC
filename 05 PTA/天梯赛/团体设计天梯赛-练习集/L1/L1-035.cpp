#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	vector<string>vt;
	string s;
	while(1)
	{
		cin>>s;
        if(s==".") break;
		vt.push_back(s);
	}
	if(vt.size()>=14) cout<<vt[1]<<" and "<<vt[13]<<" are inviting you to dinner...\n";
	else if(vt.size()>=2) cout<<vt[1]<<" is the only one for you...\n";
	else cout<<"Momo... No one is for you ...\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

