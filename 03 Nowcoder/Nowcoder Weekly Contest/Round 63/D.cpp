#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x;
	cin>>x;
    if(x==0)
    {
        cout<<"1 1 1\n1 1 1\n1 1 1\n";
        return ;
    }
	cout<<"2 1 1\n";
	cout<<x<<" "<<x<<" "<<x<<"\n";
	cout<<"1 1 2\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
