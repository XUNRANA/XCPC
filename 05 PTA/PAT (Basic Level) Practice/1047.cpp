#include <bits/stdc++.h>
using namespace std;
int cnt[1010];
void solve()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c;
        scanf("%d-%d %d",&a,&b,&c);
        // cout<<a<<" "<<b<<" "<<c<<"\n";
        cnt[a]+=c;
    }
    int mx=0;
    for(int i=1;i<=1000;i++) mx=max(mx,cnt[i]);
    for(int i=1;i<=1000;i++) if(cnt[i]==mx)
    {
        cout<<i<<" "<<mx<<"\n";
        return ;
    }
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
