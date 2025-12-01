#include <bits/stdc++.h>
using namespace std;
#define N 2005
int a[N],b[N],f[N][N],n;
int query(int x,int y)
{
	if(x>=y) return 0;
	if(f[x][y]!=-1) return f[x][y];
	cout<<"? "<<x<<" "<<y<<"\n";
	fflush(stdout);
	int tmp;
	cin>>tmp;
	return f[x][y]=tmp;
}
int ck(int x,int y)
{
	return query(x,y)^query(x+1,y)^query(x,y-1)^query(x+1,y-1);
}
int main()
{
	cin>>n;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i-1,res=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(ck(a[mid],i)) res=mid,r=mid-1;
			else l=mid+1;
		}
		for(int j=i;j>res;j--) a[j]=a[j-1];
		a[res]=i;
		res=0;
		for(int j=1;j<=i;j++) b[a[j]]=j;
		for(int j=i-1;j>=1;j--) 
		{
			res^=(b[j]>b[i]);
			f[j][i]=res^f[j][i-1];
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;i++) b[a[i]]=i;
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	fflush(stdout);
	return 0;
}
