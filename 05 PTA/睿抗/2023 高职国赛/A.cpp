#include <bits/stdc++.h>
using namespace std;

#define int long long
int fx(int x,int y)
{
    return abs(x*x-x*y-y*y);
}
void solve()
{
    int x,y;
    cin>>x>>y;
    vector<int>a;
    a.push_back(1);
    a.push_back(1);
    while(1)
    {
        int x=a.back();
        int y=a[a.size()-2];
        a.push_back(x+y);
        if(x+y>1e5) break;
    }


    x=lower_bound(a.begin(),a.end(),x)-a.begin();
    cout<<"("<<a[x+1]<<", "<<a[x]<<")"<<"\n";
    y=upper_bound(a.begin(),a.end(),y)-a.begin();
    y--;
    cout<<"("<<a[y]<<", "<<a[y-1]<<")"<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
