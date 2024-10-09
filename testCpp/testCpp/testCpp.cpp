#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> getCycle(int v, vector<int>& from) {
    vector<int> ans = { v };
    for (int i = from[v]; i != v; i = from[i]) ans.push_back(i);
    return ans;
}

void dfs(vector<vector<int>>& graph, vector<int>& visited, int v,
    vector<int>& from, vector<int>& cycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (visited[to] == 0) {
            from[to] = v;
            dfs(graph, visited, to, from, cycle);
            if (!cycle.empty()) return;
        }
        else if (visited[to] == 1) {
            from[to] = v;
            cycle = getCycle(to, from);
            return;
        }
    }
    visited[v] = 2;
}

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    int V, E; in >> V >> E;
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int a, b; in >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    vector<int> visited(V, 0);
    vector<int> from(V, -1);
    vector<int> cycle;
    for (int i = 0; i < V && cycle.empty(); i++) {
        if (visited[i] == 0) {
            dfs(graph, visited, i, from, cycle);
        }
    }
    /*for (int i = 0; i < V; i++) {
        out << i + 1 << " - " << visited[i] << "\n";
    }*/
    for (int i : cycle) {
        out << i + 1 << " ";
    }
}
