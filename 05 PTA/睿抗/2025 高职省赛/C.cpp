#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x;
	cin>>x;
	if(x==1) cout<<"gugugu\n";
	else if(x==2) cout<<"gagaga\n";
	else if(x==3) cout<<"jijiji\n";
	else if(x==4) cout<<"miaomiaomiao\n";
	else cout<<"wangwangwang\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
