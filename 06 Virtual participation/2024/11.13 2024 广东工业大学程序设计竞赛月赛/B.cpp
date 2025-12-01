#include <bits/stdc++.h>
using namespace std;
int n,x;
int a[1010];
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans1,ans2,s=0;
	for(int i=n;i>=1;i--) 
	{
		s+=a[i];
		if(s>=x) 
		{
			ans1=n-i+1;
			break;
		}
	}
	ans2=min(n,x);
	cout<<ans1<<" "<<ans2<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//     cin>>T;
    while(T--) solve();
}
