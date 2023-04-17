#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    ifstream fin("input.txt");
    fin >> n >> m;

    vector<vector<int>> graph(n + 1); // список суміжності графу
    int u, v;
    for (int i = 0; i < m; i++) {
        fin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<int> bfs(n + 1, 0); // bfs-номери вершин
    queue<int> q; // черга для обходу

    bfs[start] = 1;
    q.push(start);

    cout << "Current Vertex\tBFS Number\tQueue Contents\n";
    //cout << start << "\t\t" << bfs[start] << "\t\t";
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v : graph[cur]) {
            if (!bfs[v]) { // якщо вершина ще не пройдена
                bfs[v] = bfs[cur] + 1; // bfs-номер на 1 більше від батьківської
                q.push(v);
            }
        }

        cout << cur << "\t\t" << bfs[cur] << "\t\t";
        queue<int> temp = q; // копіюємо чергу для виведення на екран
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}
