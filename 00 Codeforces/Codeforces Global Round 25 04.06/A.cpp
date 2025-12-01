#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int c1=count(s.begin(),s.end(),'1');
	if(c1%2==0&&c1!=2) cout<<"YES\n";
	else if(c1==2)
	{
		if(s.find('1')+1!=s.rfind('1')) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
