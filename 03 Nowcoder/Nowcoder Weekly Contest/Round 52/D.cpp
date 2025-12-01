#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
    cin>>n;
    priority_queue<string,vector<string>,less<string>>q;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        q.push(s);
    }
    while(!q.empty())
    {
        string s=q.top();
        q.pop();
        cout<<s[0];
        if(s.size()==1) continue;
        q.push(s.substr(1));
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
