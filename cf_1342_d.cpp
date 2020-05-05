#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n_buckets(const vector<int>& ms, const vector<int>& cs) {
    vector<int> limits(ms);
    for (auto it = next(limits.rbegin()); it != limits.rend(); ++it) {
        *it += *prev(it);
    }

    int nbuckets = 0;
    for (int i = 0; i < cs.size(); ++i) {
        nbuckets = max(nbuckets, (limits[i] + cs[i] - 1) / cs[i]);
    }
    return nbuckets;
}

int main(int argc, char** argv) {
    int n, k;
    cin >> n >> k;

    vector<int> ms(k);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        ms[m - 1]++;
    }

    vector<int> cs;
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        cs.emplace_back(c);
    }

    int nBuckets = n_buckets(ms, cs);
    vector<vector<int>> buckets(nBuckets);

    int pos = 0;
    for (int m = 0; m < k; ++m) {
        for (int i = 0; i < ms[m]; ++i) {
            auto& b = buckets[pos++];
            if (pos == buckets.size()) {
                pos = 0;
            }
            b.emplace_back(m + 1);
        }
    }

    cout << buckets.size() << endl;
    for (const auto& r: buckets) {
        cout << r.size() << " ";
        for (auto v: r) {
            cout << v << " ";
        }
        cout << endl;
    }
}