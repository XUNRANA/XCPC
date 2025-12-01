#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(n-(upper_bound(a+1,a+1+n,i)-a)+1>=i)
		{
			cout<<i<<"\n";
			return ;
		}
	}
    cout<<"0\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
