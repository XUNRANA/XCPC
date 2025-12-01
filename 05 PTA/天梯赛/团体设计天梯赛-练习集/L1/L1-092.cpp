#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a*b==c) cout<<"Lv Yan\n";
	else if(a+b==c) cout<<"Tu Dou\n";
	else cout<<"zhe du shi sha ya!\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

