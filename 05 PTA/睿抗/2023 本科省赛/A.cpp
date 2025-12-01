#include <bits/stdc++.h>
using namespace std;


int a[3][2];
void solve()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        a[y-1][x]++;
    }
    cout<<a[0][0]<<" "<<a[1][0]<<" "<<a[2][0]<<"\n";
    cout<<a[0][1]<<" "<<a[1][1]<<" "<<a[2][1]<<"\n";
    for(int i=0;i<=2;i++) 
    if(a[i][0]>a[i][1])
    {
        cout<<"The first win!\n";
        return ;
    }
    else if(a[i][0]<a[i][1])
    {
        cout<<"The second win!\n";
        return ;
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
