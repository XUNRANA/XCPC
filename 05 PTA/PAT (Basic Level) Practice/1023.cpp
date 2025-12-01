#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    vector<int>cnt(10);
    for(auto &i:cnt) cin>>i;
    int f=0;
    for(int i=1;i<10;i++) 
    if(cnt[i]) 
    {
        cout<<i;
        f=1;
        cnt[i]--;
        break;
    }
    for(int i=0;i<10;i++) while(cnt[i]--) cout<<i;
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

