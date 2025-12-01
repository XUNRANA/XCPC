#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s,t;
    int ans=0;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    s=s+s;
    for(int i=0;i<n;i++) if(s.substr(i,m)==t) ans++;
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
