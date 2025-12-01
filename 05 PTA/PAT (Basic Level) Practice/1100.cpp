#include <bits/stdc++.h>
using namespace std;


void solve()
{
    set<string>id;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        id.insert(s);
    }
    int m;
    cin>>m;
    set<string>c;
    set<string>cc;
    string ans="99999999";
    while(m--)
    {
        string s;
        cin>>s;
        cc.insert(s);
        if(id.count(s)) c.insert(s);
        ans=min(ans,s.substr(6,8));
    }

    cout<<c.size()<<"\n";
    if(c.empty())
    {
        for(auto i:cc)
        if(i.substr(6,8)==ans)
        {
            cout<<i<<"\n";
            return ;
        }
    }
    else
    {
        ans="99999999";
        for(auto i:c) ans=min(ans,i.substr(6,8));
        for(auto i:c) 
        if(i.substr(6,8)==ans)
        {
            cout<<i<<"\n";
            return ;
        }
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
