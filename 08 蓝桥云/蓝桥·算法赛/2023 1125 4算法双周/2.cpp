#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
	{
		int s=(a+b+c)/2;
		cout<<s*(s-a)*(s-b)*(s-c);
	}
	else cout<<"-1\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
