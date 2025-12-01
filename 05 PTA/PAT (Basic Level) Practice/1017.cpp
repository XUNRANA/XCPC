#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string a;
    int b;
    cin>>a>>b;
    int d=0;
    string ans="";
    for(auto i:a)
    {
        ans+=(d*10+i-'0')/b+'0';
        d=(d*10+i-'0')%b;
    }
    int i=0,f=0;
    while(ans[i]=='0'&&i<ans.size()) i++;
    while(i<ans.size()) 
    {
        f=1;
        cout<<ans[i++];
    }
    if(f) cout<<" "<<d<<"\n";
    else cout<<0<<" "<<d<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

