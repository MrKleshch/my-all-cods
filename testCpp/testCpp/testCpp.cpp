#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    map<string, int> words;

    int team; string word;
    for (int i = 0; i < m; ++i) {
        cin >> team >> word;
        words[word] = team;
    }

    vector<int> wins(n, 0);
    for (const auto& elem : words) ++wins[elem.second - 1];
    for (int elem : wins) cout << elem << " ";
    return 0;
}
