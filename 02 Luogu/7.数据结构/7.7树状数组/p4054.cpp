#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[310][310],t[310][310][110],op,x,y,x1,x2,y11,y2,c;
int lowbit(int x)
{
	return x&-x;
}
void update(int x,int y,int k,int cr)
{
	for(int i=x;i<=n;i+=lowbit(i))
	for(int j=y;j<=m;j+=lowbit(j))
	t[i][j][cr]+=k;
}
int sum(int x,int y,int cr)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	for(int j=y;j;j-=lowbit(j))
	res+=t[i][j][cr];
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
	{
		cin>>x;
		a[i][j]=x;
		update(i,j,1,x);
	}
	cin>>q;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>c;
			update(x,y,-1,a[x][y]);
			a[x][y]=c;
			update(x,y,1,c);
		}
		else
		{
			cin>>x1>>x2>>y11>>y2>>c;
			cout<<sum(x2,y2,c)-sum(x1-1,y2,c)-sum(x2,y11-1,c)+sum(x1-1,y11-1,c)<<"\n";
		}
	}
}
