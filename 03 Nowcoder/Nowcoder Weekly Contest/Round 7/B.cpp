#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int ans1=0,ans2=0;
    int s1=0,s2=1;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<s.size();i++)
    {
        int t=s[i]-'0';
        if(t!=s1) ans1+=i;
        if(t!=s2) ans2+=i;
        s1^=1;
        s2^=1;
    }
    cout<<min(ans1,ans2)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
