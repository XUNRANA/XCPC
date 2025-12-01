#include <bits/stdc++.h>
using namespace std;
#define int long long
int c0,c1,ans0,ans1,j,k;
void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) 
    {
        if(s[i]=='1') c1++,ans1+=abs(i-j),j+=2;
        else c0++,ans0+=abs(i-k),k+=2;
    }
    if(c0==c1) cout<<min(ans1,ans0);
    else if(c0>c1) cout<<ans0;
    else cout<<ans1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
