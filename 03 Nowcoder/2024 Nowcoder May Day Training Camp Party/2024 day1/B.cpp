#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l;
int a[510];
string s[50];
void solve()
{
	cin>>n>>k;
	l=min(10ll,a[n]-k+1ll);
	if(n<20) 
	{
		cout<<s[n].substr(k-1,l)<<"\n";
		return ;
	}
    int i;
	for(i=n;i>=20;i--)
	{
		//cout<<i<<" "<<k<<"\n";
		//cout<<i<<" "<<k<<" "<<a[i-2]<<"\n";
		if(k>a[i-2]) k-=a[i-2];
		else i--;
	}
	//cout<<i<<" "<<k<<"\n";
	if(k+l-1>s[i].size()) cout<<(s[i]+s[i-1]+s[i]).substr(k-1,l)<<"\n";	
	else cout<<s[i].substr(k-1,l)<<"\n";
}
signed main()
{
	a[1]=6;                       
	a[2]=7;
	s[1]="COFFEE";
	s[2]="CHICKEN";
	for(int i=3;i<=500;i++)
	{
		if(i<20) s[i]=s[i-2]+s[i-1];
		a[i]=a[i-2]+a[i-1];
		if(a[i]>1e17) 
		{
			for(int j=i;j<=500;j++) a[j]=a[i];
			break;
		}
	}
//	for(int i=1;i<10;i++) cout<<i<<" "<<" "<<a[i]<<" "<<s[i]<<"\n";
//	for(int i=1;i<=500;i++) cout<<i<<" "<<a[i]<<"\n";
	int T=1;
	cin>>T;
	while(T--) solve();
}
