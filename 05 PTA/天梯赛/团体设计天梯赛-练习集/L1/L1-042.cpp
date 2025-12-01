#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int m,d,y;
	scanf("%d-%d-%d",&m,&d,&y);
	printf("%04d-%02d-%02d",y,m,d);
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

