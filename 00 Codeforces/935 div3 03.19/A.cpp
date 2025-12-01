#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c;
	d=b%3;
	if(d!=0&&c<3-d) cout<<"-1\n";
	else 
	{
		cout<<a+(b+c+2)/3<<"\n";
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
