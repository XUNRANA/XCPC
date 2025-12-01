#include <bits/stdc++.h>
using namespace std;
#define N 10000000
int s,x,x1,p[N];
void init()
{
	for(int i=2;i<N;i++)
	if(!p[i]) for(int j=i+i;j<N;j+=i) p[j]=1;
}
int is(int x)
{
	if(x<N) return !p[x];
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}

void solve()
{                    
	init();
	cin>>s>>x;
	if(__gcd(s,x)==1) cout<<"1\n"<<s;
	else
	{
		if(s&1)
		{
			int s1=s-1;
			for(int i=2;i<s1;i++)
			{
				if(is(i)&&is(s1-i))
				{
					if(i!=x&&s1-i!=x)
					{
						cout<<3<<"\n";
						cout<<1<<" "<<i<<" "<<s1-i<<"\n";
						return ;
					}
				}	
			}
		}
		else
		{
			for(int i=2;i<s;i++)
			{
				if(is(i)&&is(s-
				i))
				{
					if(__gcd(i,x)==1&&__gcd(s-i,x)==1)
					{
						cout<<2<<"\n";
						cout<<i<<" "<<s-i<<"\n";
						return ;
					}
				}
			}
		}
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
