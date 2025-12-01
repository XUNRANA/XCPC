#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int cnt=count(s.begin(),s.end(),'1');
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') ans+=cnt-1;
        else ans+=cnt+1;
    }
    cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
