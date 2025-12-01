#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int > a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<ll > pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    vector<ll > ans(n+1,0);


    auto check=[&](int left,int right){
        if(pre[right-1]-pre[left-1]>a[right]){
            return 1;
        }
        return 0;
    };

    priority_queue<pair<int ,int > ,vector<pair<int ,int > >, less<pair<int ,int > > > Q;

    vector<vector<pair<int,int > > > pushQue(n+1);
    for(int i=3;i<=n;i++){
        int left=1,right=i-2+1;
        while(left<right){
            int mid=(left+right)/2;
            if(check(mid,i)){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        int cnt=left-1;
        if(cnt>=1&&cnt<=i-2){
            int leftCorner=i-cnt+1;
            int rightCorner=i;
            pushQue[leftCorner].push_back({i,rightCorner});
        }
    }


    for(int i=1;i<=n;i++){
        for(auto pr:pushQue[i]){
            Q.push(pr);
        }
        while(!Q.empty()){
            if(Q.top().second<i){
                Q.pop();
            }else{
                break;
            }
        }
        if(Q.empty()){
            ans[i]=0;
        }else{
            ans[i]=pre[Q.top().first]-pre[Q.top().first-i];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" \n"[i==n];
    }
    
    return ;

}

int main(){
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
