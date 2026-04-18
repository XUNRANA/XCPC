#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[10];

1 2 3 4 5 6 7 8


a1/(a1+b2)*a3/(a3+b4) *a1/(a1+b3)  
a1/(a1+b2)*b4/(a3+b4) *a1/(a1+b4)


a1*a1*a3/(a1+b2)/(a1+b3)/(a3+b4)
a5*a5*a7/(a5+b6)/(a5+b7)/(a7+b8)
a1/(a1+b5)

a1*a1*b4/(a1+b2)/(a1+b4)/(a3+b4)

void fx(vector<int>p)
{
    return 
}
void solve()
{
    for(int i=1;i<=8;i++) cin>>a[i]>>b[i];
    vector<int>p;

    for(int i=1;i<=8;i++) p.push_back(i);
    
    do{
        fx(p);
    }while(next_permutation(p.begin(),p.end()));

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}