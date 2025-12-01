#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n==2) cout<<"1 1\n1 2\n";
	else if(n==3) cout<<"2 1\n2 3\n3 1\n";
	else if(n==4) cout<<"1 1\n1 3\n4 3\n4 4\n";
	else 
	{
		cout<<"1 1\n1 3\n1 4\n2 1\n5 5\n";
		for(int i=6;i<=n;i++) cout<<i<<" "<<i<<"\n";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
