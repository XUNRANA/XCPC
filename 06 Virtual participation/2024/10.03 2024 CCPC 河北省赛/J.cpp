#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
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
int inv(int x)
{
	return ksm(x,P-2);
}
int m,a[10];
int fx(int x) //i¸ö1    n¸ö1           i*9+1=10^i
{
	return (ksm(10,x)-1+P)%P*inv(9)%P;
}

void solve()
{
	cin>>m;
	int f=0;
	for(int i=0;i<10;i++) 
	{
		cin>>a[i];
		if(i&&a[i]) f=1;
	}
	
	if(f==0||(m==1&&a[0])) cout<<"0\n";
	else
	{
		int res=0;
		for(int i=1;i<10;i++)
		{
			if(a[i])
			{
				res=i;
				a[i]--;
				m--;
				break;
			}
		}
		
		if(m<=a[0]) 
		{
			res=res*ksm(10,m)%P;
			cout<<res<<"\n";
			return ;
		}
		
		res=res*ksm(10,a[0])%P;
		m-=a[0];
		
		for(int i=1;i<10;i++)
		{
			if(a[i])
			{
				if(m>a[i])
				{
					res=res*ksm(10,a[i])%P;
					res=(res+fx(a[i])*i%P)%P;
					m-=a[i];
					
				}	
				else
				{
					res=res*ksm(10,m)%P;
					res=(res+fx(m)*i%P)%P;
					break;	
				}
			}
		}	
		cout<<res<<"\n";
	}
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
/*
3
3 1 0 0 0 3 0 0 0 0 0
1 2 0 0 0 0 0 0 0 0 0
4 0 1 1 1 3 0 0 0 0 0
*/
