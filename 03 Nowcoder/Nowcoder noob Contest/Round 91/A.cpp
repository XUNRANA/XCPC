#include <bits/stdc++.h>
using namespace std;
char a[10][10];
void solve()
{
    for(int i=1;i<=6;i++) for(int j=1;j<=7;j++) cin>>a[i][j];
    if(a[1][4]=='.') cout<<"o\n";
    else
    {
        if(a[6][4]=='|') cout<<"p\n";
        else cout<<"m\n";
    }
    
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
//	cin>>t1;
	while(t1--) solve(); 
}