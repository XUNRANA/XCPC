#include <bits/stdc++.h>
using namespace std;
void solve()
{
	char a,b; 
	cin>>a>>b;
	int cnt=a-'A'+b-'A';
	if(cnt>=26) cout<<char(cnt/26+'A')<<char(cnt%26+'A');
	else cout<<char(cnt+'A');
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
