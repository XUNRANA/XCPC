#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	if(k==1)
	{
		for(int i=1;i<n;i++) cout<<n<<" ";
		cout<<n-1<<"\n";
	}
	else
	{
		if(k&1)
		{
			for(int i=1;i<n;i++) cout<<n<<" ";
			cout<<n-1<<"\n";
		}
		else
		{
			for(int i=1;i<n-1;i++) cout<<n-1<<" ";
			cout<<n<<" "<<n-1<<"\n";
		}
	}
	
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

