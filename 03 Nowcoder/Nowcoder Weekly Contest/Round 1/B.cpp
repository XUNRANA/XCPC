#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;
string s;
void solve()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>s;
    s=" "+s;
    map<int,int>c[2];
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='B') c[0][a[i]]++;
        else c[1][a[i]]++;
        st.insert(a[i]);
    }
    for(auto i:st)
    {
        if(c[0].count(i)&&c[1].count(i)) ans+=c[0][i]*c[1][i];
    }
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
