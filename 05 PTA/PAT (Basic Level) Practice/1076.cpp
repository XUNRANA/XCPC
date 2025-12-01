#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int n;
    cin>>n;
    string ans="";
    for(int i=1;i<=n;i++)
    {
        string s;
        for(int j=0;j<4;j++) 
        {
            cin>>s;
            reverse(s.begin(),s.end());
            for(int i=0;i<s.size();i++)
            if(s[i]=='T') ans+=s[i+2]-'A'+'1';
        }
    }
    cout<<ans<<"\n";

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
