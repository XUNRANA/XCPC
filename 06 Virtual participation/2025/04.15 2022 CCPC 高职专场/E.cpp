#include <bits/stdc++.h>
using namespace std;
bool ck(int x)
{
	int c=0;
	for(int i=30;i>=0;i--) if(x>>i&1) c++;
	return c%2==0;
}
void solve()
{
	int x;
	cin>>x;
	while(!ck(x)) x++;
	cout<<x<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

