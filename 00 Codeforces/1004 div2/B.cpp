#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    // vector<int>cnt(1010,0);
    int n,x;
    cin>>n;
    map<int,int>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        while(cnt[x]==2) x++;
        cnt[x]++;
    }
    for(auto [x,y]:cnt) if(y!=2) 
    {
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
}


signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

