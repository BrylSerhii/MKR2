#include <iostream>
#include <vector>

/*Задано зв'язний неорієнтовний граф без петель і кратних ребер. Дозволяється видаляти з нього ребра. Потрібно отримати дерево. Посилання.
Вхідні дані: Перший рядок містить кількість вершин n (1 ≤ n ≤ 100) та кількість ребер m графу відповідно.
Наступні m пар чисел задають ребра графу. Гарантується, що граф зв'язний.
Вихідні дані: Виведіть пари чисел - ребра, які увійдуть у дерево. Ребра можна виводити у довільному порядку.*/


using namespace std;

void dfs(int u, vector<bool>& visited, const vector<vector<int>>& graph, vector<pair<int, int>>& tree) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            tree.push_back({u, v});
            dfs(v, visited, graph, tree);
        }
    }
}

vector<pair<int, int>> buildTree(int n, const vector<pair<int, int>>& edges) {

    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<int, int>> tree;
    vector<bool> visited(n + 1, false);
    dfs(1, visited, graph, tree);

    return tree;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    vector<pair<int, int>> tree = buildTree(n, edges);

    for (const auto& edge : tree) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
