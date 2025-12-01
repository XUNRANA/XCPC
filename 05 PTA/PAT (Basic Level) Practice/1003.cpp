#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin>>s;
    int p=-1,t=-1;
    vector<int>cnt(3,0);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='P') cnt[0]++;
        else if(s[i]=='A') cnt[1]++;
        else if(s[i]=='T') cnt[2]++;
        if(s[i]=='P') p=i;
        else if(s[i]=='T') t=i;
    }
    if(cnt[0]!=1||cnt[2]!=1||cnt[0]+cnt[1]+cnt[2]!=s.size())
    {
        cout<<"NO\n";
        return ;
    }
    int c1=p;
    int c2=t-p-1;
    int c3=s.size()-t-1;
    if(c2<1||c1*c2!=c3) cout<<"NO\n";
    else cout<<"YES\n"; 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}