#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int a,b;
	cin>>a>>b;
	int t=abs(a-b);
	if(a==b) cout<<"0\n";
	else if(a>b)
	{	
		if(t%2==0) cout<<"1\n";
		else cout<<"2\n";
	}
	else
	{
		if(t%2==1) cout<<"1\n";
		else if(t/2%2==1) cout<<"2\n";
		else cout<<"3\n";
	} 
	//加一个 正奇数x 
	//减一个 正偶数y 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
