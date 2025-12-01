#include <bits/stdc++.h>
using namespace std;
int n,a[110];
void solve()
{
    cin>>n;
    a[1]=n;
    for(int i=2;i<=n;i++) a[i]=i-1;
    for(int i=2;i<=n;i++)
    if(max(a[i-1],a[i])%i!=i-1)
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
