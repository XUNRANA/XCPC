#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> frac;

// 计算最小公倍数
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// 计算所有击打时间
vector<ll> get_hit_times(int n, vector<frac>& notes, ll base_lcm) {
    vector<ll> hit_times;
    ll current_time = 0;
    for (auto& note : notes) {
        ll p = note.first, q = note.second;
        ll unit_time = base_lcm / q * p;
        hit_times.push_back(current_time);
        current_time += unit_time;
    }
    return hit_times;
}

void solve() {
    int n1, n2;
    cin >> n1 >> n2;
    
    vector<frac> snare(n1), bass(n2);
    set<ll> q_values;
    
    for (int i = 0; i < n1; i++) {
        cin >> snare[i].first >> snare[i].second;
        q_values.insert(snare[i].second);
    }
    for (int i = 0; i < n2; i++) {
        cin >> bass[i].first >> bass[i].second;
        q_values.insert(bass[i].second);
    }
    
    // 计算所有 q 的最小公倍数
    ll base_lcm = 1;
    for (ll q : q_values) {
        base_lcm = lcm(base_lcm, q);
    }
    
    // 计算军鼓和底鼓的击打时间
    vector<ll> snare_hits = get_hit_times(n1, snare, base_lcm);
    vector<ll> bass_hits = get_hit_times(n2, bass, base_lcm);
    
    // 使用双指针计算交集
    int i = 0, j = 0, count = 0;
    while (i < snare_hits.size() && j < bass_hits.size()) {
        if (snare_hits[i] == bass_hits[j]) {
            count++;
            i++;
            j++;
        } else if (snare_hits[i] < bass_hits[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}