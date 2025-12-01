#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	if(s.size()>=23&&s.substr(0,23)=="https://ac.nowcoder.com"||s.size()>=15&&s.substr(0,15)=="ac.nowcoder.com") cout<<"Ac\n";
	else if(s.size()>=24&&s.substr(0,24)=="https://www.nowcoder.com"||s.size()>=16&&s.substr(0,16)=="www.nowcoder.com") cout<<"Nowcoder\n";
    else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
