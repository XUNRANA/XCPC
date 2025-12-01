#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int s=0;
    for(int i=0;i<n;i++){
        if(s>=a[i]){
            s++;
        }else{
            s--;
        }
    }
    cout<<s<<" ";
    s=0;
    for(int i=n-1;i>=0;i--){
        if(s>=a[i]){
            s++;
        }else{
            s--;
        }
    }
    cout<<s<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}
