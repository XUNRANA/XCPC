#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size()/2;i++)
    {
        int j=s.size()-1-i;
        if(s[i]!=s[j])
        {
            int c1=s[i]-'a';
            int c2=s[j]-'a';
            ans+=min(abs(c1-c2),26-abs(c1-c2));
        }
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
