#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	long long ans=0; 
	for(int i=1;i<n;i++)
	{
		int val=abs(s[i]-s[i-1]);
		ans+=min(min(i,n-i),min(k-1,n-k+1))*val;
	}
	cout<<ans<<"\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

