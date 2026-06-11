#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const double INF = 0x3f3f3f3f;

void solve(){
    int n;
    cin>>n;
    vector<int > x(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    vector<double > p(n+1,0);
    vector<int > v(n+1,0);
    // double ans=INF;
    vector<double > dp(n+1,0);
    double ans=INF;
    for(int i=1;i<=n;i++){
        double winp=1.0*(1000-x[i])/1000;
        double losep=1.0*x[i]/1000;
        double mi=winp*i+losep*(20+n);
        dp[i]=winp*i;
        // cout<<"??"<<dp[i]<<winp<<endl;
        int id=-1;
        for(int j=1;j<i;j++){
            double cnt=winp*p[j]*(v[j]+i)+dp[j];
            double res=cnt+losep*p[j]*(v[j]+20+n);
            if(res<mi){
                id=j;
                dp[i]=cnt;
                mi=res;
            }
        }
        if(id>-1){
            p[i]=p[id]*1.0*x[i]/1000;
            v[i]=v[id]+20;
        }else{
            p[i]=losep;
            v[i]=20;
        }
        ans=min(ans,mi);
        // cout<<"id "<<id<<" dp"<<i<<": "<<dp[i]<<endl;
    }
    // cout<<fixed<<setprecision(12)<<ans<<endl;
    printf("%.12lf\n",ans);
}

int main (){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}