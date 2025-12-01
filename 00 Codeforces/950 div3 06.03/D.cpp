#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b==0? a:gcd(b,a%b);
}
int n,a[200010],b[200010],c[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) b[i]=gcd(a[i],a[i+1]);
	if(n==3)
	{
		cout<<"YES\n";
		return ;
	}
	
	int f=0;
	for(int i=1;i<=n-3;i++) if(b[i]>b[i+1]) f=1;
	if(f==0)
	{
		cout<<"YES\n";
		return ;
	}
	
	f=0;
	for(int i=2;i<=n-2;i++) if(b[i]>b[i+1]) f=1;
	if(f==0)
	{
		cout<<"YES\n";
		return ;
	}
	
	for(int i=1;i<=n-2;i++)
	{
		//i-1 i i+1 i+2
		if(b[i]>b[i+1])
		{
			for(int i1=max(1,i-1);i1<=min(i+2,n);i1++)
			{
				for(int j=1,k=1;j<=n;j++) 
				if(j==i1) continue;
				else c[k++]=a[j];
				
				int f=0;
				for(int j=1;j<n-2;j++) 
				if(gcd(c[j],c[j+1])>gcd(c[j+1],c[j+2])) f=1;
				
				if(f==0)
				{
					cout<<"YES\n";
					return ;
				}
			}
			cout<<"NO\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
