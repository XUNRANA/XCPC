#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	vector<int>d(10,0);
	for(auto i:s) d[i-'0']++;
	for(int i=0;i<10;i++) if(d[i]) cout<<i<<":"<<d[i]<<"\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

