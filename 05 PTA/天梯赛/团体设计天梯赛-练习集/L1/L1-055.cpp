#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b;
	cin>>a>>b;
	int x1,x2,x3;
	cin>>x1>>x2>>x3;
	if(x1==x2&&x2==x3)
	{
		cout<<"The winner is ";
		if(x1) cout<<"b: "<<b<<" + 3";
		else cout<<"a: "<<a<<" + 3";
		return ;
	}
	
	if(a>b)
	{
		cout<<"The winner is ";
		if(!x1||!x2||!x3) cout<<"a: "<<a<<" + "<<(!x1)+(!x2)+(!x3)<<"\n";
		return ;
	}
	else
	{
		cout<<"The winner is ";
		if(x1||x2||x3) cout<<"b: "<<b<<" + "<<(x1)+(x2)+(x3)<<"\n";
		return ;
	}
	
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

