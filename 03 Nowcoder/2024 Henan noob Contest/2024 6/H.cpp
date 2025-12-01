#include <bits/stdc++.h>
using namespace std;
int a[4]; 
double c(double x,double y,int op)
{
	if(op==0) return x+y;
	else if(op==1) return x-y;
	else if(op==2) return x*y;
	else if(op==3) return x/y;
	else if(op==4) return y-x;
	else return y/x;
}
void solve() 
{
	for(int i=0;i<4;i++)
	{
		string s;
		cin>>s;
		if(s=="A") a[i]=1;
		else if(s=="J") a[i]=11;
		else if(s=="Q") a[i]=12;
		else if(s=="K") a[i]=13;
		else if(s=="10") a[i]=10;
		else a[i]=s[0]-'0';
	}
	sort(a,a+4);
	do
	{
		for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		for(int k=0;k<6;k++)
		for(int l=0;l<6;l++)
		if(abs(c(c(c(a[0],a[1],i),a[2],j),a[3],k)-24.0)<1e-8||abs(c(c(a[0],a[1],i),c(a[2],a[3],j),k)-24.0)<1e-8)
        {
        	cout<<"YES\n";
       		return ;
	   	}		
	}while(next_permutation(a,a+4));
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
