#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l;
    string s,a,b;
    cin>>s;
    if(s.size()&1)
    {
        l=s.size()-1;
        l/=2;
        a=s.substr(0,l);
        b=s.substr(l+1,2*l+1);
        if(a==b) cout<<"-1\n";
        else cout<<b<<s[s.size()/2]<<a;
    }
    else
    {
        a=s.substr(0,s.size()/2);
        b=s.substr(s.size()/2,s.size());
        if(a==b) cout<<"-1\n";
        else cout<<b<<a;
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

