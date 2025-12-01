#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b;
	cin>>a>>b;
	if(a>b) swap(a,b);
	if((int)((sqrt(5)+1)/2*(b-a))==a) cout<<"DHY\n";//先手输 
	else cout<<"DHY\n";//先手赢 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
} 
