#include <bits/stdc++.h>
using namespace std;

int a[5];
void solve()
{
	for(int i=1;i<=4;i++) cin>>a[i];
	sort(a+1,a+1+4);
	if(a[1]==a[2]&&a[3]==a[4]) cout<<"2\n";
	else if(a[1]==a[2]||a[2]==a[3]||a[3]==a[4]) cout<<"1\n";
	else cout<<"0\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
