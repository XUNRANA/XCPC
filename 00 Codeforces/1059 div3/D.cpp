#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int op,int l,int r)
{
    cout<<op<<" "<<l<<" "<<r<<"\n";
    cout.flush();
    int x;
    cin>>x;
    fflush(stdout);
    return x;
}
//3 1 2  
//3 2 2


//2 1 3 4
//2 2 4 5
void solve()
{
    int n;
    cin>>n;
    fflush(stdout);
    int len=query(2,1,n)-(1+n)*n/2;
    int l=1,r=n;

    while(l<=r)
    {
        int m=l+r>>1;
        int x1=query(1,1,m);
        int x2=query(2,1,m);
        if(x2-x1==len) r=m-1;
        else l=m+1;
    }

    cout<<"! "<<l-len+1<<" "<<l<<"\n";
    cout.flush();
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
