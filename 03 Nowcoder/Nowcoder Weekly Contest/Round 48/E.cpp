#include <bits/stdc++.h>
using namespace std;
#define int long long
int sn[26][200010],sm[26][200010];
int n,ans;
void solve()
{
	string s;
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=n;i>=1;i--)
	{
		int t=s[i]-'a';
        for(int j=0;j<26;j++) sn[j][i]=sn[j][i+1];
        sn[t][i]++;
        for(int j=0;j<26;j++) sm[j][i]=sm[j][i+1];
        sm[t][i]+=n-i+1;
    }
    for(int i=1;i<=n;i++)
    {
        int t=s[i]-'a';
        int i1=n-i+1,sum=0,c=0;
        for(int j=0;j<26;j++)
        {
            if(j==t) continue;
            if(i<i1)
            {      
                c+=sn[j][i]-sn[j][i1];
                sum+=sm[j][i1];
            }
            else sum+=sm[j][i];
        }
        ans+=c*i+sum;
    }
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
