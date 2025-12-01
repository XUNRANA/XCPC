#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
	string s,t;
	cin>>n>>s>>t;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i]&&i+1<n)
        {
            s[i]=(s[i]-'0')^1+'0';
            s[i+1]=(s[i+1]-'0')^1+'0';
            //cout<<i<<" "<<s<<"\n";
            v.push_back({i+1,i+2});
        }
        else if(s[i]!=t[i])
        {
    
            cout<<"-1\n";
            return ;
        }
    }
    cout<<v.size()<<"\n";
    for(auto i:v) cout<<i.first<<" "<<i.second<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
