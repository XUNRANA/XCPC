#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 19260817
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int res=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return res;
}
int getinv(int a)
{
	int x=0,y=0;
	int d=exgcd(a,P,x,y);
	return d==1? (x%P+P)%P:-1;
}
void solve()
{
	string a,b;
	int x=0,y=0;
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		x=x*10+a[i]-'0';
		x%=P;
	}	
	for(int i=0;i<b.size();i++)
	{
		y=y*10+b[i]-'0';
		y%=P;
	}	
	if(!y)
	{
		cout<<"Angry!\n";
		return ;
	}
	//cout<<x*getinv(y)%P<<"\n";
	cout<<x*ksm(y,P-2)%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
