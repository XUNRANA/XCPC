#include <bits/stdc++.h>
using namespace std;
int ask(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<"\n";
	int t;
	cin>>t;
	return t;
}
void solve()
{
	int n,id=0;
	cin>>n;
	for(int i=1;i+1<=n;i+=2) 
	{
		int t=ask(i,i+1);
		if(t)
		{
			id=i;
			break;
		}
	}
	
	if(id==0)
	{
		if(n%2==0) cout<<"! 1\n";
		else 
		{
			int t1=ask(n,n-1);
			int t2=ask(n,n-2);
			int t3=ask(n,n-3);
			if(t1&&t2&&t3) cout<<"! 2\n";
			else cout<<"! 1\n";
		}
		return ;
	}
	
	if(id!=1)
	{
		int t=ask(id,id-1);
		if(t)
		{
			t=ask(id,id-2);
			if(t) cout<<"! 2\n";//id:id+1,id-1,id-2
			else cout<<"! 1\n";//id:id+1,id-1   没有id-2
		}
		else
		{
			t=ask(id+1,id-1);
			if(t)
			{
				t=ask(id+1,id-2);
				if(t) cout<<"! 2\n";//id+1:id id-1 id-2 
				else cout<<"! 1\n";//id+1:id id-1 没有id-2 
			}
			else cout<<"! 1\n";//id、id+1中有一个能和所有的相连，而他们都不能和id-1相连，非菊花图 
		}
	}
	else
	{
		int t1=ask(1,3);
		int t2=ask(1,4);
		int t3=ask(2,3);
		int t4=ask(2,4);
		if((t1&&t2)||(t3&&t4)) cout<<"! 2\n";
		else cout<<"! 1\n";
	} 
}
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
