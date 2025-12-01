#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010];
void solve()
{
	int n;
	cin>>a[1]>>a[2]>>n;
	int i=1,j=3;
	while(j<=n)
	{
		int x=a[i]*a[i+1];
		if(x>=10) 
		{
			a[j++]=x/10;
			a[j++]=x%10;
		}
		else a[j++]=x;
		i++;
	}
	for(int i=1;i<=n;i++)
    {
        if(i!=1) cout<<" ";
        cout<<a[i];
    }
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
