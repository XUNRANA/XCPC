#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    if(n==1) cout<<ksm(2,P-2)<<"\n";
    else if(n==2) cout<<"1\n";
    else if(n==3) cout<<3*ksm(4,P-2)%P<<"\n";
    else if(n==4) cout<<ksm(2,P-2)<<"\n";
    else if(n==5) cout<<"1\n";
    else
    {
        if(n%5==2||n%5==0) cout<<"1\n";
        else
        {
            if(n%5==1)
            {
                int c=n/5;
                int fz=ksm(2,c);
                cout<<(fz-1)*ksm(fz,P-2)%P<<"\n";
            }
            else if(n%5==3)
            {
                int c=n/5;
                int fz=ksm(2,c+2);
                cout<<(fz-1)*ksm(fz,P-2)%P<<"\n";
            }
            else 
            {
                int c=n/5;
                int fz=ksm(2,c+1);
                cout<<(fz-1)*ksm(fz,P-2)%P<<"\n";
            }
        }
    }
    // cout<<3*ksm(4,P-2)%P<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}