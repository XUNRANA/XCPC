#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x;
    cin>>x;
    for(int n=1;n<10;n++)
    {
        int y=x*x*n;
        int p;
        if(x<10) p=10;
        else if(x<100) p=100;
        else if(x<1000) p=1000;
        if(y%p==x) 
        {
            cout<<n<<" "<<y<<"\n";
            return ;
        }
    }
    cout<<"No\n";

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
