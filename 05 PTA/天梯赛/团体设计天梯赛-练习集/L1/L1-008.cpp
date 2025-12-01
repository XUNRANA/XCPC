#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b;
	cin>>a>>b;
	int s=0,f=-1;
	for(int i=a,j=0;i<=b;i++)
	{
		printf("%5d",i);
		j++;
		if(j%5==0) 
		{
			printf("\n");
			f=1;
		}
		else f=0;
		s+=i;
	}
	if(!f) printf("\n");
	printf("Sum = %d\n",s);
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

