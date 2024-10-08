#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<int>& visited, int color) {
    visited[v] = color;
    for (int to : graph[v]) {
        if (visited[to] == 0) {
            dfs(to, graph, visited, color);
        }
    }
}

int main() {
    ifstream in;  // для чтения данных
    ofstream out; // для записи данных
    in.open("input.txt");
    out.open("output.txt");

    int vertex, edge; in >> vertex >> edge;
    vector<vector<int>> graph(vertex);
    vector<int> visited(vertex, 0);
    for (int i = 0; i < edge; ++i) {
        int a, b; in >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    int color = 1;
    for (int i = 0; i < vertex; ++i) {
        if (visited[i] == 0) {
            dfs(i, graph, visited, color++);
        }
    }

    for (int i : visited) out << i << " ";

    in.close();
    out.close();

}
