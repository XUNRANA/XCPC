#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a,da,b,db,sa=0,sb=0;
    cin>>a>>da>>b>>db;
    while(a)
    {
        if(a%10==da) sa=sa*10+da;
        a/=10;
    }
    while(b)
    {
        if(b%10==db) sb=sb*10+db;
        b/=10;
    }
    cout<<sa+sb<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

