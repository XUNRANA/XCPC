#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int s,x,x1,f[N];
vector<int>p;
void init()
{
	for(int i=2;i<N;i++)
	if(!f[i]) 
	{
		p.push_back(i);
		for(int j=i+i;j<N;j+=i) f[j]=1;
	}
}

void solve()
{                    
	init();
	cin>>s>>x;
	
	if(__gcd(x,s)==1)
	{
		cout<<"1\n"<<s<<"\n";
		return ;
	}
	
	if(s==2)
	{
		cout<<"2\n1 1";
		return ;
	}
	if(s==4)
	{
		cout<<"2\n5 -1";
		return ;
	}
	
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

