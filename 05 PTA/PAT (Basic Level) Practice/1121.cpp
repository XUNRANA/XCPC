#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    cin>>s;
    int cnt=0;
    int x=0;
    int f=1;
    for(auto i:s)
    {
        cnt++;
        x=x*10+(i-'0');
        if(x%cnt) f=0;
    }
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
    
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
