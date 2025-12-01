#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int a[200010];

void solve()
{
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>s;
    s=" "+s;
    vector<int>b,r;
    for(int i=1;i<=n;i++) 
    if(s[i]=='R') r.push_back(a[i]);
    else b.push_back(a[i]); 


    sort(r.begin(),r.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int mi=min(r.size(),b.size());
    int ans=0;
    for(int i=0;i<mi;i++) ans+=r[i]+b[i];
    if(mi<r.size()) ans+=r[mi];
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