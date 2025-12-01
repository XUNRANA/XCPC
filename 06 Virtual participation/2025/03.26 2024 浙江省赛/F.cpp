#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s[1010];
int a[1010];
void solve()
{
    cin>>n;
    vector<int>cnt(20,0);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>a[i];
        cnt[a[i]]++;
    }
    for(int i=10;i>=0;i--) cnt[i]+=cnt[i+1];
    string ans="";
    for(int i=1;i<=n;i++)
    {
        // cout<<cnt[a[i]+1]+1<<"\n";
        for(int j=0;j<max((int)s[i].size()-(cnt[a[i]+1]+1),0ll);j++) ans+=s[i][j];
    }
    ans[0]=toupper(ans[0]);
    cout<<"Stage: "<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
