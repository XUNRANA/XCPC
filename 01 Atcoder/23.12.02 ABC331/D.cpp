#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010],n,q,x1,y11,x2,y2;
char ch;
int get(int x,int y)
{
	if(x>n) return get(n,y)*(x/n)+get(x%n,y);
	if(y>n) return get(x,n)*(y/n)+get(x,y%n);
	return a[x][y];
}
signed main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) 
	{
		cin>>ch;
		a[i+1][j+1]=a[i][j+1]+a[i+1][j]-a[i][j]+(ch=='B');
	}
	while(q--)
	{
		cin>>x1>>y11>>x2>>y2;
		x2++,y2++;
		cout<<get(x1,y11)+get(x2,y2)-get(x1,y2)-get(x2,y11)<<"\n";
	}
}
