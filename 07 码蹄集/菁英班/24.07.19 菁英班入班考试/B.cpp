#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,m,s=0;
    scanf("%d,%d",&n,&m);
    for(int i=n;i<=m;i++) if(i%2==0&&i%3==0) s+=i;
    cout<<s;
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

