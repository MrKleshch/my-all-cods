#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о результатах голосования
struct CandidateResult {
    string name;
    int electoralVotes;

    // Оператор сравнения для сортировки по убыванию голосов выборщиков
    // и по лексикографическому порядку при равенстве голосов
    bool operator<(const CandidateResult& other) const {
        if (electoralVotes != other.electoralVotes)
            return electoralVotes > other.electoralVotes;
        return name < other.name;
    }
};

int main() {
    int n; // Количество штатов
    cin >> n;

    map<string, int> stateElectors; // Количество выборщиков от каждого штата
    map<string, map<string, int>> stateVotes; // Количество голосов за кандидатов в каждом штате

    // Чтение информации о штатах
    for (int i = 0; i < n; ++i) {
        string state;
        int electors;
        cin >> state >> electors;
        stateElectors[state] = electors;
    }

    int m; // Количество проголосовавших
    cin >> m;

    // Чтение голосов избирателей
    for (int i = 0; i < m; ++i) {
        string state, candidate;
        cin >> state >> candidate;
        stateVotes[state][candidate]++;
    }

    map<string, int> candidateElectoralVotes; // Суммарные голоса выборщиков за кандидатов

    // Определение победителя в каждом штате
    for (const auto& state : stateVotes) {
        const string& stateName = state.first;
        const map<string, int>& votes = state.second;

        string winner;
        int maxVotes = 0;

        for (const auto& candidate : votes) {
            const string& candidateName = candidate.first;
            int voteCount = candidate.second;

            // Определяем победителя в штате с учетом лексикографического порядка
            if (voteCount > maxVotes || (voteCount == maxVotes && candidateName < winner)) {
                maxVotes = voteCount;
                winner = candidateName;
            }
        }

        // Добавляем голоса выборщиков победителю
        candidateElectoralVotes[winner] += stateElectors[stateName];
    }

    // Добавляем кандидатов с нулевыми голосами выборщиков
    for (const auto& state : stateVotes) {
        for (const auto& candidate : state.second) {
            if (candidateElectoralVotes.find(candidate.first) == candidateElectoralVotes.end()) {
                candidateElectoralVotes[candidate.first] = 0;
            }
        }
    }

    // Сбор результатов для сортировки
    vector<CandidateResult> results;
    for (const auto& entry : candidateElectoralVotes) {
        results.push_back({ entry.first, entry.second });
    }

    // Сортировка по убыванию голосов выборщиков и лексикографическому порядку
    sort(results.begin(), results.end());

    // Вывод результата
    for (const auto& result : results) {
        cout << result.name << " " << result.electoralVotes << endl;
    }

    return 0;
}
