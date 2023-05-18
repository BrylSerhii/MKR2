#include <iostream>
#include <vector>

/*Задано орієнтовний граф. Знайдіть найкоротшу відстань від заданої вершини до усіх інших вершин графа.
На вхід - матриця суміжності графа та номер вершини.
Імплементувати відповідну функцію. Відстані виводити у консоль, виводити “-1”, якщо шляху немає.*/

using namespace std;

const int INF = 1e9;

void DijkstraShortestPath(const vector<vector<int>>& graph, int source) {
    int numVertices = graph.size();

    vector<int> distance(numVertices, INF);
    vector<bool> visited(numVertices, false);

    distance[source] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int minDistance = INF;
        int minIndex = -1;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && graph[minIndex][v] != 0 && distance[minIndex] != INF &&
                distance[minIndex] + graph[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph[minIndex][v];
            }
        }
    }

    for (int i = 0; i < numVertices; ++i) {
        if (distance[i] == INF) {
            cout << "-1" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
    };

    DijkstraShortestPath(graph, 0);

    return 0;
}
