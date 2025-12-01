#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>p;
int is(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=200000;i++) if(is(i)) p.push_back(i);
    int ans=0;
    for(int i=n-1,cnt=0;i<=m-1;i++)
    {
        cnt++;
        cout<<p[i];
        if(cnt%10==0) cout<<"\n";
        else if(i!=m-1) cout<<" ";
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