#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"1\n";
        cout<<a<<"\n";
        return ;
    }
    if(a>b) swap(a,b);
    if(b%a==0) 
    {
        cout<<"2\n";
        cout<<a<<" "<<b-a<<"\n";
    }
    else cout<<"-1\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
