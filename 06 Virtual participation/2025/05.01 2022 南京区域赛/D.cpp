#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define int ll

template<typename T>
class SortedList {
    //update O(√N) with query O(log(N))
private:
    vector<vector<T>> lists; // blocked list
    vector<int> list_lens;     // The length of each sublist
    vector<T> mins;          // The minimum value of each sublist
    vector<int> fenwick;       // Fenwick tree
    int load;                  // The maximum capacity of each sublist
    bool rebuild;              // Whether the Fenwick tree needs to be rebuilt
    int length;                // length of sorted list

    // Build a fenwick tree instance.
    void fenwick_build() {
        fenwick = list_lens;
        for (int i = 0; i < fenwick.size(); ++i) {
            if ((i | i + 1) < int(fenwick.size()))
                fenwick[i | i + 1] += fenwick[i];
        }
        rebuild = false;
    }

    // Update `fen_tree[index] += value`.
    void fenwick_update(int index, int value) {
        if (!rebuild) {
            while (index < fenwick.size()) {
                fenwick[index] += value;
                index |= index + 1;
            }
        }
    }

    // Return `sum(_fen_tree[:end])`.
    int fenwick_query(int end) {
        if (rebuild) {
            fenwick_build();
        }
        int result = 0;
        while (end) {
            result += fenwick[end - 1];
            end &= end - 1;
        }
        return result;
    }

    // Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`).
    pair<int, int> fenwick_findkth(int k) {
        if (k < list_lens[0]) return {0, k};
        if (k >= length - list_lens.back())
            return {int(list_lens.size()) - 1, k + list_lens.back() - length};

        if (rebuild) {
            fenwick_build();
        }
        int idx = -1;
        for (int d = __bit_width(fenwick.size()) - 1; d >= 0; --d) {
            int right_idx = idx + (1 << d);
            if (right_idx < int(fenwick.size()) && k >= fenwick[right_idx]) {
                idx = right_idx;
                k -= fenwick[idx];
            }
        }
        return {idx + 1, k};
    }

    // Delete value at the given `(pos, idx)`.
    void delete_at(int pos, int idx) {
        lists[pos].erase(lists[pos].begin() + idx);
        list_lens[pos]--;
        length--;
        fenwick_update(pos, -1);

        if (list_lens[pos] == 0) {
            lists.erase(lists.begin() + pos);
            list_lens.erase(list_lens.begin() + pos);
            mins.erase(mins.begin() + pos);
            rebuild = true;
        } else {
            mins[pos] = lists[pos][0];
        }
    }

    // Return an index pair that corresponds to the first position of `value` in the sorted list.
    pair<int, int> locate_left(T value) {
        if (lists.empty()) {
            return {0, 0};
        }
        int lo = -1, pos = lists.size() - 1;
        while (lo + 1 < pos) {
            int mi = (lo + pos) >> 1;
            if (value <= mins[mi]) pos = mi;
            else lo = mi;
        }

        if (pos > 0 && value <= lists[pos - 1].back()) {
            pos--;
        }
        auto& lst = lists[pos];
        int idx = lower_bound(lst.begin(), lst.end(), value) - lst.begin();
        return {pos, idx};
    }

    // Return an index pair that corresponds to the last position of `value` in the sorted list.
    pair<int, int> locate_right(T value) {
        if (lists.empty()) {
            return {0, 0};
        }
        int pos = 0, hi = lists.size();
        while (pos + 1 < hi) {
            int mi = (pos + hi) >> 1;
            if (value < mins[mi]) hi = mi;
            else pos = mi;
        }

        auto& lst = lists[pos];
        int idx = upper_bound(lst.begin(), lst.end(), value) - lst.begin();
        return {pos, idx};
    }

public:
    // Initialize sorted list instance.
    SortedList(int _load = 200) : load(_load), rebuild(true), length(0) {}
    SortedList(vector<T> value, int _load = 200) : load(_load), rebuild(true), length(value.size()) {
        sort(value.begin(), value.end());
        int cnt = 0;
        for (int i = 0; i < length; i += load) {
            lists.push_back({});
            for (int j = i; j < i + load; j++) {
                lists[cnt].push_back(value[j]);
            }
            list_lens.push_back(lists[cnt].size());
            mins.push_back(value[i]);
            cnt++;
        }
    }

    // Add `value` to sorted list.
    void add(T value) {
        if (lists.empty()) {
            lists.push_back({value});
            list_lens.push_back(1);
            mins.push_back(value);
            rebuild = true;
            length++;
            return;
        }
        length++;
        auto [pos, idx] = locate_right(value);
        fenwick_update(pos, 1);
        lists[pos].insert(lists[pos].begin() + idx, value);
        list_lens[pos]++;
        mins[pos] = lists[pos][0];
        if (list_lens[pos] > 2 * load) {
            lists.insert(lists.begin() + pos + 1, vector<T>(lists[pos].begin() + load, lists[pos].end()));
            list_lens.insert(list_lens.begin() + pos + 1, lists[pos].size() - load);
            mins.insert(mins.begin() + pos + 1, lists[pos][load]);
            list_lens[pos] = load;
            lists[pos].resize(load);
            rebuild = true;
        }
    }

    // Remove `value` from sorted list if it is a member.
    void discard(T value) {
        if (lists.empty()) {
            return;
        }
        auto [pos, idx] = locate_right(value);
        if (idx > 0 && lists[pos][idx - 1] == value) {
            delete_at(pos, idx - 1);
        }
    }

    // Remove `value` from sorted list; `value` must be a member.
    void remove(T value) {
        if (lists.empty()) {
            throw invalid_argument("Value not found in list");
        }
        auto [pos, idx] = locate_right(value);
        if (idx == 0 || lists[pos][idx - 1] != value) {
            throw invalid_argument("Value not found in list");
        }
        delete_at(pos, idx - 1);
    }

    // Return the Kth element from sorted list.
    T get_kth(int k) {

        auto [pos, idx] = fenwick_findkth(k);
        return lists[pos][idx];
    }

    T operator[] (int k) {
        if (k < 0) return get_kth(length + k);
        return get_kth(k);
    }

    // Return the first index to insert `value` in the sorted list.
    int bisect_left(T value) {
        auto [pos, idx] = locate_left(value);
        return fenwick_query(pos) + idx;
    }

    // Return the last index to insert `value` in the sorted list.
    int bisect_right(T value) {
        auto [pos, idx] = locate_right(value);
        return fenwick_query(pos) + idx;
    }

    // Return whether value in the sorted list.
    bool exist(T value) {
        if (lists.empty()) return false;
        auto [pos, idx] = locate_left(value);
        return idx < list_lens[pos] and lists[pos][idx] == value;
    }

    // Return number of occurrences of `value` in the sorted list.
    int count(T value) {
        return bisect_right(value) - bisect_left(value);
    }

    // Return the size of the sorted list.
    int size() {
        return length;
    }

    bool empty() {
        return size() == 0;
    }

    class Iterator {
    private:
        const SortedList<T>* parent;
        int pos;
        int idx;

    public:
        Iterator(const SortedList<T>* _parent, int _pos, int _idx)
            : parent(_parent), pos(_pos), idx(_idx) {}

        T operator*() const {
            return parent->lists[pos][idx];
        }

        Iterator& operator++() {
            idx++;
            if (idx >= parent->list_lens[pos]) {
                pos++;
                idx = 0;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return pos == other.pos && idx == other.idx;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() const {
        if (lists.empty()) {
            return end();
        }
        return Iterator(this, 0, 0);
    }

    Iterator end() const {
        return Iterator(this, lists.size(), 0);
    }

    class ReverseIterator {
    private:
        const SortedList<T>* parent;
        int pos;
        int idx;

    public:
        ReverseIterator(const SortedList<T>* _parent, int _pos, int _idx)
            : parent(_parent), pos(_pos), idx(_idx) {}

        T operator*() const {
            return parent->lists[pos][idx];
        }

        ReverseIterator& operator--() {
            idx--;
            if (idx < 0) {
                pos--;
                if (pos >= 0) {
                    idx = parent->list_lens[pos] - 1;
                } else {
                    idx = 0;
                }
            }
            return *this;
        }

        ReverseIterator operator--(int) {
            ReverseIterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const ReverseIterator& other) const {
            return pos == other.pos && idx == other.idx;
        }

        bool operator!=(const ReverseIterator& other) const {
            return !(*this == other);
        }
    };

    ReverseIterator rbegin() const {
        if (lists.empty()) {
            return rend();
        }
        int last_pos = lists.size() - 1;
        int last_idx = list_lens[last_pos] - 1;
        return ReverseIterator(this, last_pos, last_idx);
    }

    ReverseIterator rend() const {
        return ReverseIterator(this, -1, 0);
    }
};

void solve() {
    int n, k, m, c, d; cin >> n >> k >> m >> c >> d;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] + c + (i - 1) * d;
    }
    b[0] = -1;
    SortedList<int> x, y;

    for (int i = 1; i <= m - 1; i++) {
        y.add(b[i]);
    }
    for (int i = m; i <= n; i++) {
        x.add(b[i]);
    }

    int res = 0;

    for (int l = 1; l + m - 1 <= n; l++) {
        int r = l + m - 1;
        y.add(b[r]);
        x.discard(a[r]);
        y.discard(b[l - 1]);
        x.add(a[l - 1]);
        int L = 1, R = 1e16;
        while (L < R) {
            int m = L + R >> 1LL;
            int cntmx1 = x.size() - x.bisect_left(m);
            int cntmn1 = x.size() - x.bisect_right(m);
            int cntmx2 = y.size() - y.bisect_left(m + (l - 1) * d);
            int cntmn2 = y.size() - y.bisect_right(m + (l - 1) * d);
            int mx = cntmx1 + cntmx2, mn = cntmn1 + cntmn2;

            if (mx < k) r = m;
            else if (mn >= k) l = m + 1;
        }
        res = max(res, L);
    }
    cout << res << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}