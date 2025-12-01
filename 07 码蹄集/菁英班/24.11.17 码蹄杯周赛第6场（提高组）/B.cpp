#include <bits/stdc++.h> 
using namespace std;
bool is(int x)
{
	int t=sqrt(x);
	return t*t==x;
}
void solve()
{
	int n;
	cin>>n;
	long long ans=0;
	if(is(n)) ans+=8;
	for(int i=1;i*i<n;i++)
	{
        int t=n-i*i;
		if(is(t)) ans+=6*4;
		for(int j=1;i*i+j*j<n;j++)
		{
			int t=n-i*i-j*j;
			if(is(t)) ans+=4*8;
            for(int k=1;i*i+j*j+k*k<n;k++)
			{
				int t=n-i*i-j*j-k*k;
				if(is(t)) ans+=16;
			}
		}
	}
	cout<<ans<<"\n";
}

int main( )
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();	
}

