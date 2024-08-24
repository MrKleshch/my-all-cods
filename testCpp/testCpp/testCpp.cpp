#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> trees(n);

    for (int i = 0; i < n; ++i) cin >> trees[i];

    unordered_map<int, int> count;
    int unique = 0, l = 0, minLength = n + 1, minL = 0, minR = 0;

    for (int r = 0; r < n; ++r) {
        if (++count[trees[r]] == 1) ++unique;

        while (unique == k) {
            if (r - l + 1 < minLength) {
                minLength = r - l + 1;
                minL = l;
                minR = r;
            }
            if (--count[trees[l]] == 0) --unique;
            ++l;
        }
    }

    cout << minL + 1 << " " << minR + 1;
    return 0;
}
