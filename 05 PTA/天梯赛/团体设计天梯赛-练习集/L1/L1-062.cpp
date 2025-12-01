#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x)
{
	int sum=0;
	while(x)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		int y=x;
		int sum=0;
		sum+=x%10;
		x/=10;
		sum+=x%10;
		x/=10;
		sum+=x%10;
		x/=10;
		if(2*sum==f(y)) cout<<"You are lucky!\n";
		else cout<<"Wish you good luck.\n";
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

