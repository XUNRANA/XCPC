#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b;
	cin>>a>>b;
	if(b>0) printf("%d/%d=%.2f\n",a,b,1.0*a/b);
	else if(b<0) printf("%d/(%d)=%.2f\n",a,b,1.0*a/b);
	else printf("%d/%d=Error\n",a,b);
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

