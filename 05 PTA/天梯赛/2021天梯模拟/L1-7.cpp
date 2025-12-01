#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x;
	cin>>x;
	int y;
	int res;
	if(x<=1) y=1,res=1;
	else if(x<=11) y=11,res=2;
	else if(x<=111) y=111,res=3;
	else y=1111,res=4;
	
	string ans="";
	while(y%x!=0)
	{
		ans+=y/x+'0';
		y%=x;
		y=y*10+1;
        res+=1;
	}
	ans+=y/x+'0';
	cout<<ans<<" "<<res<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
