#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s,t;
	cin>>s;
	t="";
	t+=s[1];
	for(int i=0;i<5;i++) 
	if(i==1) continue;
	else t+=s[i];
	cout<<t<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
