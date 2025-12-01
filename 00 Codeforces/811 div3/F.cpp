#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[4];
void solve() 
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    arr[1] = a + c - b >> 1;  
    arr[2] = a + b - c >> 1;  
    arr[3] = b + c - a >> 1;  
    if (arr[1] < 0 ||  arr[2] < 0 || arr[3] < 0 || arr[1] + arr[2] + arr[3] >= n || a + b + c & 1) puts("NO");//判断无解   
    else{  
        puts("YES");  
        int idx = 3,r = 0;  
        for (int i = 1;i <= 3;i++){//找出一个根   
            if (!arr[i]){  
                r = i;  
                break;  
            }  
        }  
        if (!r) r = idx = 4;//如果没找到直接随便认一个   
        for (int i = 1;i <= 3;i++){  
            if (i == r) continue;  
            printf("%d ",r);//挨个加边   
            for (int j = 1;j < arr[i];j++) printf("%d\n%d ",++idx,idx);  
            printf("%d\n",i);  
        }  
        while (idx < n) printf("1 %d\n",++idx);//加剩下的点   
    }  
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}