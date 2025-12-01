#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    vector<char>a;
    a.push_back('a');
    a.push_back('s');
    a.push_back('d');
    a.push_back('w');
    int res=1e9;
    for(auto i:a)
    {
        char p=' ';
        int ans=0;
        for(auto j:s)
        {
            if(p!=' ')
            {
                if(p==j) continue;
                if(p==i||j==i) ans++;
                else ans+=2;
            }
            p=j;
        }
        res=min(res,ans);
    }
    cout<<res<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
// 	cin>>T;
	while(T--) solve();
}
