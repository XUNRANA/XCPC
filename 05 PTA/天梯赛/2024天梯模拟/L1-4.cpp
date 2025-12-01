#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c==a*b) cout<<"Lv Yan\n";
	else if(c==a+b) cout<<"Tu Dou\n";
	else cout<<"zhe du shi sha ya!\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
