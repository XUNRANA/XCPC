#include <bits/stdc++.h>
using namespace std;


int is[200010];
int a[20][1010];


void solve()
{
    int x,n,m;
    vector<int>b;
    cin>>x;
    b.push_back(x);
    is[x]=1;
    cin>>x;
    b.push_back(x);
    is[x]=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];

    vector<int>p;
    for(int i=1;i<=n;i++) p.push_back(i);

    for(int j=1;j<=m;j++)
    {
        vector<int>np;
        for(auto i:p)
        {
            int x=a[i][j];
            
            int f=1;
            for(auto k:b) if(is[k+x]) f=0;

            if(is[x]||f) 
            {
                cout<<"Round #"<<j<<": "<<i<<" is out.\n";
                continue;
            }
            np.push_back(i);
            b.push_back(x);
            is[x]=1;
        }
        p=np;
    }
    if(p.size())
    {
        cout<<"Winner(s):";
        for(auto i:p) cout<<" "<<i;
    }
    else cout<<"No winner.\n";
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
