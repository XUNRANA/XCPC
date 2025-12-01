#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010];
void solve()
{
	cin>>a[1]>>a[2]>>n;
	int j=3;
	int f=1;
	while(j<=n)
	{
		int x=a[f]*a[f+1];
		if(x>=10)
		{
			a[j++]=x/10;
			a[j++]=x%10;
		}
		else a[j++]=x;
		f++;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n]; 
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

