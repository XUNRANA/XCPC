#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define endl '\n'

void solve(){
    int ppmax;
    cin>>ppmax;
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    
    ll acc=(300*a+300*b+200*c+100*d+50*e)*100000/(300*(a+b+c+d+e+f));
    
    if(acc%10>=5) acc+=10;
    acc-=acc%10;



    ll pp=10*max(0ll,(320*a+300*b+200*c+100*d+50*e-64*4*(a+b+c+d+e+f))*5*ppmax)/(320*(a+b+c+d+e+f));


    if(pp%10>=5) pp+=10;
    pp-=pp%10;



    printf("%.2f%% %.0f\n",1.0*acc/1000,1.0*pp/10);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
} 
