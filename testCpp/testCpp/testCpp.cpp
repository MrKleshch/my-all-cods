#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> shirts(n);
    for (int i = 0; i < n; ++i) cin >> shirts[i];

    int m; cin >> m;
    vector<int> trousers(m);
    for (int i = 0; i < m; ++i) cin >> trousers[i];

    int i = 0, j = 0;
    int nbest = 0, mbest = 0;

    while (i < n && j < m) {
        if (abs(shirts[i] - trousers[j]) < abs(shirts[nbest] - trousers[mbest])) {
            nbest = i;
            mbest = j;
        }

        if (shirts[i] > trousers[j]) {
            ++j;
        }
        else if (shirts[i] == trousers[j]) {
            break;
        }
        else {
            ++i;
        }
    }

    cout << shirts[nbest] << " " << trousers[mbest] << std::endl;

    return 0;
}
