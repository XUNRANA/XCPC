#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
    int n,x,y,z,ans=0,c1=0;
    cin>>n>>s>>x>>y>>z;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='1') c1++;
        else 
        {
            if(c1)
            {
                c1--;
                ans++;
            }
        }
    }
    cout<<min(y,ans)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
