#include <bits/stdc++.h>
using namespace std;


void print(vector<string>a)
{    
    int k=a.size()-1;
    if(k%2==0) k--;

    vector<string>b;
    while(k>=0)
    {
        b.push_back(a[k]);
        k-=2;
    }
    k=0;
    while(k<a.size())
    {
        b.push_back(a[k]);
        k+=2;
    }

    int f=0;
    for(auto i:b)
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
    cout<<"\n";
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector< pair<int,string> >c;
    for(int i=1;i<=n;i++)
    {
        string a;
        int b;
        cin>>a>>b;
        c.push_back({-b,a});
    }
    sort(c.begin(),c.end());
    int cnt=n/k;
    int t=n%k;
    vector<string>vv;
    for(int i=0;i<min(cnt+t,n);i++) vv.push_back(c[i].second);
    print(vv);
    for(int i=cnt+t;i<n;i+=cnt)
    {
        vv.clear();
        for(int j=i;j<i+cnt;j++) vv.push_back(c[j].second);
        print(vv);
    }
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
