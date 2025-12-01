#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string a,b;
	cin>>a>>b;
	int ans=a.size()+b.size();
	int cnt=0;
	for(int i=0;i<min((int)a.size(),(int)b.size());i++)
	{
		if(a[i]==b[i]) cnt++;
		else break;
	}
	if(cnt) cout<<ans-cnt+1<<"\n";
	else cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
