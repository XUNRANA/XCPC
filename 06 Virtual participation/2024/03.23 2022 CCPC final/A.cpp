#include <bits/stdc++.h>
using namespace std;
#define int long long 

void f(int x)
{
	for(int i=63;i>=0;i--) if(x>>i&1) cout<<"1";
	else cout<<"0";
	cout<<"\n";
}
void solve()
{
	int x,y,k;
	cin>>x>>y>>k;
	if(x>y) swap(x,y);

	if(k<=0||x==y)
	{
		cout<<abs(x-y)<<"\n";
		return ;
	}
	
	if((x^y)<=k||x+1==y)
	{
		cout<<1<<"\n";
		return ;
	}	
	
	int lk=log2(k)+1,ans;
	int lx=x-(x>>lk<<lk);
	int ly=y-(y>>lk<<lk);
	if((y>>lk)-(x>>lk)>=1)
	{
		if(log2(k+1)==(int)log2(k+1)) ans=((y>>lk)-(x>>lk)-1)*2;
		else ans=((y>>lk)-(x>>lk)-1)*3;
	}
	else
	{
		cout<<2<<"\n";
		return ;
	}

	int t=(1ll<<lk)-1;
	

	if(t-lx==0) ans+=1;
	else if(t-lx<=k) ans+=2;
	else ans+=3;
	

	
	if(ly==0) ans+=0;
	else if(ly<=k) ans+=1;
	else ans+=2;
	cout<<ans<<"\n";
	
	/*
	f(lx);
	f(ly);
	f(t);
	
	f(x);
	f(y);
	f(k);
	*/
		
}
signed main()
{
	int t1;
	cin>>t1;
	while(t1--) solve();
}
