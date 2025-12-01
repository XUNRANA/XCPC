#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],b[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    int f=0;
    for(int i=2;i<=n;i++) if(a[i]==a[i-1]) f=1;
    if(f) cout<<"shuishui"<<endl;
    else cout<<"sha7dow"<<endl;
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
