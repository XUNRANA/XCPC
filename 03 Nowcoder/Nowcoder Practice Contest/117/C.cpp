#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,k,l;
    cin>>t;
    long long sum;
    while(t--)
    {
        cin>>n>>m>>k;
        sum=n+m*2;
        if(k%2==0||(k%2==1&&sum/k<=n))
        {
            l=sum%k;
            m=min(l/2,m);
            n=l-m*2;
            cout<<m+n<<endl;
        }
        else cout<<m-n*(k/2)<<endl;
    }
}