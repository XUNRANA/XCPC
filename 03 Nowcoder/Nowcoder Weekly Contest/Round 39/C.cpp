#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,t;
void solve()
{
    cin>>n>>p;
    map<int,int>m;
    while(n--)
    {
        cin>>t;
        m[t%3]++;
    }
    if(m[0]!=0) cout<<"1\n";
    else if(m[1]!=0&&m[2]!=0) cout<<"2\n";
    else cout<<"3\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
