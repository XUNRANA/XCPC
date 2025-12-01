#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
    int mx=0,s=0;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i) continue;
		int sum=0;
		int k=n;
		for(int j=i;k%j==0&&k;j++)
		{
			sum++;
			k/=j;
		}
		if(sum>mx) 
		{
			mx=sum;
			s=i;
		}
	}
	
	if(mx==0) 
	{
		cout<<"1\n"<<n<<"\n";
		return ;
	}
	cout<<mx<<"\n";
	cout<<s;
	for(int i=s+1;i<=s+mx-1;i++) cout<<"*"<<i;
	cout<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

