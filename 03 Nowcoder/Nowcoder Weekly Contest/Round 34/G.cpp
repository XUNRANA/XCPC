#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p[100010],vt[100010],cr,cw,ans;
string s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	cin>>s;
	s=" "+s;
	if(count(s.begin(),s.end(),'R')==n||count(s.begin(),s.end(),'R')==0)
	{
		if(is_sorted(p+1,p+1+n)) cout<<"0\n";
		else cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vt[i]) continue;
		int cnt=0,r=0,w=0,t=i;
		while(!vt[t])
		{
			cnt++;
			vt[t]=1;
			r|=(s[t]=='R');
			w|=(s[t]=='W');
			t=p[t];
		}
		ans+=cnt-1;
		if(cnt>1)
		{
			if(!r) cw++;
			else if(!w) cr++;
		}
	}
	cout<<ans+2*max(cr,cw);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

