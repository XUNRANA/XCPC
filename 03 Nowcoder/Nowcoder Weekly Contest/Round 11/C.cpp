#include <bits/stdc++.h>
using namespace std;
string s;
int a[2010][2],ans;
void solve()
{
    cin>>s;
    s=" "+s;
    for(int i=1,j=1;i<s.size();i++)
    {
        if(s[i]!='0') a[i][j]=1;
        else a[i][j^1]=1;
        j^=1;
    }
    for(int i=1;i<s.size();i++) 
    {
        a[i][0]+=a[i-1][0];
        a[i][1]+=a[i-1][1];
    }
    for(int i=1;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            ans+=min(a[j][0]-a[i-1][0],a[j][1]-a[i-1][1]);
        }
    }
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
