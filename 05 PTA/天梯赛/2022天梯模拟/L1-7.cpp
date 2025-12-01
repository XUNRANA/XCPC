#include<bits/stdc++.h>
using namespace std;

int n,k,m;
int a[110][110];
void solve()
{
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	
	for(int j=2,c=1;j<=n;j+=2)
	{
		for(int i=n;i>c;i--) a[i][j]=a[i-c][j];
		for(int i=c;i>=1;i--) a[i][j]=m;
		c++;
		if(c>k) c-=k;
	}
//	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<a[i][j]<<" "; 
	for(int i=1;i<=n;i++) 
	{
		int s=0;
		for(int j=1;j<=n;j++) s+=a[i][j];
		if(i!=1) cout<<" ";
		cout<<s;
	}
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}


