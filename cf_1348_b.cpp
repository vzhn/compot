#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        vector<int> input;
        unordered_set<int> elems;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;

            elems.emplace(a);
            input.emplace_back(a);
        }

        if (elems.size() > k) {
            cout << -1 << endl;
        } else {
            vector<int> subarray(elems.begin(), elems.end());
            while (subarray.size() < k) {
                subarray.emplace_back(subarray[0]);
            }
            vector<int> ans;
            int pos = 0;
            for (int i = 0; i < input.size(); ++i) {
                while (subarray[pos % k] != input[i]) {
                    ans.emplace_back(subarray[pos % k]);
                    ++pos;
                }
                ++pos;
                ans.emplace_back(input[i]);
            }

            cout << ans.size() << " ";
            for (auto e: ans) {
                cout << e << " ";
            }
            cout << endl;
        }


    }
    return 0;
}