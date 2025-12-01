#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	cin>>s;
	double ans=1.0;
	int cnt=0,cnt1=0;
	if(s[0]=='-') ans*=1.5;
	if((s.back()-'0')%2==0) ans*=2.0;
	for(auto i:s) 
	if(isdigit(i)) 
	{
		if(i=='2') cnt1++;
		cnt++;
	}
//	cout<<cnt1<<" "<<cnt<<"\n";
	printf("%.2f%%\n",100*ans*cnt1/cnt);
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

