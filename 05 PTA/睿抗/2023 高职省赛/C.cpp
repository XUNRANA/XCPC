#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int x,s1=0,s2=0;
    for(int i=1;i<=n;i++) cin>>x,s1+=x;
    for(int i=1;i<=n;i++) cin>>x,s2+=x;
    printf("%.1f\n",s1/(s2/60.0));
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
