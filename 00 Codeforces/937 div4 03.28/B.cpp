#include <bits/stdc++.h>
using namespace std;
int n;
int a[50][50];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2==0)
			{
				if(i==1&&j==1) a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]=1;
				else if(i==1) a[i][2*j-1]=a[i][2*j]=a[i+1][2*j-1]=a[i+1][2*j]=1;
				else if(j==1) a[2*i-1][j]=a[2*i][j]=a[2*i-1][j+1]=a[2*i][j+1]=1;
				else a[2*i][2*j]=a[2*i-1][2*j]=a[2*i][2*j-1]=a[2*i-1][2*j-1]=1;
			}
		}
	}
	
	for(int i=1;i<=2*n;i++,cout<<"\n") for(int j=1;j<=2*n;j++) 
	if(a[i][j]&1) cout<<"#";
	else cout<<".";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
