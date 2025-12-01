#include <bits/stdc++.h>
using namespace std;
#define int long long
string a[10010];
int b[10010];
string f[110];
void solve()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		string name;
		int x;
		cin>>name>>x;
		f[x]=name;
		a[i]=name;
		b[i]=x;
		sum+=x;
	}	
	sum/=2*n;
	
	for(int i=0;;i++)
	{
		if(sum+i<=100&&f[sum+i]!="")
		{
			cout<<sum<<" "<<f[sum+i]<<"\n";
			return ;
		}
		if(sum-i>=0&&f[sum-i]!="")
		{
			cout<<sum<<" "<<f[sum-i]<<"\n";
			return ;
		}
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

