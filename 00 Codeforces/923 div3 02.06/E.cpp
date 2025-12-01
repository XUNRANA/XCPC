#include <bits/stdc++.h>
using namespace std;
int n,k,a[200010];
void solve()
{
	cin>>n>>k;
	int i,j=1;
	for(int k1=1;k1<=k;k1++)
	{
		i=k1;
		while(i<=n)
		{
		    a[i]=j++;
			i+=k;
			if(i>n) break;
	    }
	    if(k1%2==0)
	    {
	    	for(int i1=k1,j1=i-k;i1<j1;i1+=k,j1-=k) swap(a[i1],a[j1]);    	
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}
