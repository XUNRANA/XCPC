#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>a,b;
    for(int i=1;i*i<=n;i++)
    if(n%i==0) 
    {
        a.push_back(i);
        if(n/i!=i) a.push_back(n/i);
    }
    for(int i=1;i*i<=m;i++)
    if(m%i==0) 
    {
        b.push_back(i);
        if(m/i!=i) b.push_back(m/i);
    }
    set<int>s;
    for(auto i:a) for(auto j:b) s.insert(i*j);
    cout<<s.size()<<"\n";
    for(auto i:s) cout<<i<<" ";
    cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
