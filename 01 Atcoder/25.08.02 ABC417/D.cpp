#include <bits/stdc++.h>
using namespace std;

#define N 10010
int p[N],a[N],b[N];
void solve()
{
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++) cin>>p[i]>>a[i]>>b[i],s+=b[i];
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x-s>500) 
        {
            cout<<x-s<<"\n";
            continue;
        }

        for(int i=1;i<=n;i++) 
        if(p[i]>=x) x+=a[i];
        else x=max(x-b[i],0);
        cout<<x<<"\n";
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

