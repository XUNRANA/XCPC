#include <bits/stdc++.h>
using namespace std;
int n,m,x1,y11,x2,y2,a[1010][1010];
int main()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>x1>>y11>>x2>>y2;
		a[x1][y11]++;
		a[x2+1][y11]--;
		a[x1][y2+1]--;
		a[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++) 
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
