#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        double x;
        cin>>x;
        ans+=(long long)(1000*x)*i*(n-i+1);
    }
    printf("%.2f",ans/1000.0);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
