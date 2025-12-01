#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	if(n==1) cout<<"0\n";
	else if(n==2) cout<<"2\n";
	else if(n==3) cout<<"4\n";
	else if(n==4) cout<<"4\n";
	else if(n%2==0) cout<<"4\n";
	else cout<<"6\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
