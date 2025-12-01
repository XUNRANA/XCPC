#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    map<string,int>mp;
    int n;
    cin>>n;
    while(n--)
    {
        string s,t;
        cin>>s;
        cin.ignore();
        getline(cin,t);
        // cout<<s<<"\n"; 
        // cout<<t<<"\n";
        for(auto &i:t) if(islower(i)) i=toupper(i);
        int ans=0;
        for(int i=0;i<t.size();i++)
        {
            if(i+6<t.size()&&t.substr(i,7)=="CHATGPT") ans++;
        }
        mp[s]+=ans;
    }
    vector<pair<int,string>>ans;
    for(auto i:mp) ans.push_back({-i.second,i.first});
    sort(ans.begin(),ans.end());
    int c=0;
    for(auto i:ans) 
    {
        if(i.first)
        {
            cout<<i.second<<" "<<-i.first<<"\n";
            c++;
        }
        if(c==3) break;
    }
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
