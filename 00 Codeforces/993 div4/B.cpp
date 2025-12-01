#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin>>s;
    string ans="";
    for(int i=s.size()-1;i>=0;i--) 
    if(s[i]=='q') ans+='p';
    else if(s[i]=='p') ans+='q';
    else ans+='w';
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
