#include <bits/stdc++.h>
using namespace std;
string ans[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
void solve()
{
	while(1)
	{
        int y;
        cin>>y;
		if(y>=1&&y<=12) cout<<ans[y-1]<<"\n";
		else
        {
            cout<<"?\n";
            break;
        }
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
