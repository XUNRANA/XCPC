#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    vector<string>a;
    string s,t="";
    getline(cin,s);
    for(auto i:s)
    {
        if(i==' ')
        {
            a.push_back(t);
            t="";
        }
        else t+=i;
    }
    a.push_back(t);
    int f=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(f) cout<<" ";
        cout<<a[i];
        f=1;
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