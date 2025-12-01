#include <bits/stdc++.h>
using namespace std;
bool isz(int x)
{
	int t=sqrt(x);
	return t*t==x;
}
bool iss(int x)
{
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	if(isz(n)&&iss(n)) cout<<"2\n";
	else if(isz(n)) cout<<"0\n";
	else if(iss(n)) cout<<"1\n";
	else cout<<"3\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
