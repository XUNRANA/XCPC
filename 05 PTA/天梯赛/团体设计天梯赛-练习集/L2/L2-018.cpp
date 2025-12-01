#include <bits/stdc++.h>
using namespace std;
const int N=200010;
double a[N],b[N],c[N];
void print(double x[],int i)
{
	int cnt=0;
	for(int j=0;j<=i;j++) if(abs(x[j])+0.05>=0.1) cnt++;
	printf("%d",cnt);
	if(!cnt) printf(" 0 0.0");
	for(int j=i;j>=0;j--) if(abs(x[j])+0.05>=0.1) printf(" %d %.1f",j,x[j]);
}
void solve()
{
	int n,m,x;
	cin>>n;
	int i1=-0x3f3f3f,i2=-0x3f3f3f;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>a[x];
		i1=max(i1,x);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		cin>>b[x];
		i2=max(i2,x);
	}
	int t=i1-i2;
	while(i1-i2>=0)
	{
		double q=a[i1]/b[i2];
		c[i1-i2]=q;
		for(int i=i1,j=i2;i>=0&&j>=0;i--,j--) a[i]-=b[j]*q;
		while(a[i1]==0) i1--;
	}
	print(c,t);
	printf("\n");
	print(a,i1);
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

