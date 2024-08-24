#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> N(n);
    for (int i = 0; i < n; ++i) cin >> N[i];

    int m; cin >> m;
    vector<int> M(m);
    for (int i = 0; i < m; ++i) cin >> M[i];

    int i = 0, j = 0;
    int nbest = 0, mbest = 0;

    while (i < n && j < m) {
        if (abs(N[i] - M[j]) < abs(N[nbest] - M[mbest])) {
            nbest = i;
            mbest = j;
        }
        if (N[i] > M[j]) ++j;
        else if (N[i] < M[j]) ++i;
        else break;
    }

    cout << N[nbest] << " " << M[mbest];
    return 0;
}
