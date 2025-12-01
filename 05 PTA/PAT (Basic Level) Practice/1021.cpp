#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string s;
    cin>>s;
    vector<int>cnt(10,0);
    for(auto i:s) cnt[i-'0']++;
    for(int i=0;i<10;i++)
    {
        if(cnt[i]) cout<<i<<":"<<cnt[i]<<"\n";
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

