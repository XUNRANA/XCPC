#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int a,b;
	scanf("%lld:%lld",&a,&b);
	if(a<12||(a==12&&b==0)) printf("Only %02d:%02d.  Too early to Dang.\n",a,b);
	else 
	{
		a-=12;
		if(b!=0) a++;
		while(a--) printf("Dang");
	}
    
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

