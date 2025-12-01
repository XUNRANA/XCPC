#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,t;
	cin>>n;
	int cnt=0;
	if(n<=1) t=1,cnt=1;
	else if(n<=11) t=11,cnt=2;
	else if(n<=111) t=111,cnt=3;
	else t=1111,cnt=4;
	string ans;
	while(1)
	{
		ans+=char(t/n+'0');
		t=t%n;
		if(t==0) break;
		t=t*10+1;
		cnt++;
	}
	cout<<ans<<" "<<cnt<<"\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

