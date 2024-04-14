#include <iostream>
#include <limits>
using namespace std;

#define V 7 // Количество вершин в графе

void dijkstra(int graph[V][V], int source) {
    int itog[V]; // Массив для хранения кратчайших расстояний
    bool visited[V]; // Массив для отслеживания посещенных вершин

    // Инициализация массивов
    for (int i = 0; i < V; ++i) {
        itog[i] = INT_MAX;
        visited[i] = false;
    }
    itog[source] = 0; // Расстояние от начальной вершины до самой себя равно 0

    // Начинаем обход
    for (int count = 0; count < V - 1; ++count) {
        int minDist = INT_MAX;
        int minIndex = -1;

        // Находим вершину с минимальным расстоянием из текущих непосещенных вершин
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && itog[v] <= minDist) {
                minDist = itog[v];
                minIndex = v;
            }
        }

        // Помечаем найденную вершину как посещенную
        visited[minIndex] = true;

        // Обновляем расстояния для всех вершин, смежных с текущей
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[minIndex][v] && itog[minIndex] != INT_MAX &&
                itog[minIndex] + graph[minIndex][v] < itog[v]) {
                itog[v] = itog[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Выводим результат
    cout << "Расстояние от вершины " << (source + 1) << " и его длина\n";
    for (int i = 0; i < V; ++i) {
        cout << "До вершины " << (i + 1) << " расстояние " << itog[i] << endl;
    }
}

int main() {
    system("chcp 1251");
    int graph[V][V] = {
        {0, 1, 0, 8, 25, 0, 20},
        { 0, 0, 2, 0, 0, 0, 15 },
        { 0, 0, 0, 0, 0, 3, 0 },
        { 0, 0, 0, 0, 9, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 6 },
        { 0, 0, 0, 0, 0, 0, 4 },
        { 0, 0, 0, 0, 0, 0, 0 }
    };
    int source = 0;
    dijkstra(graph, source);
    return 0;
}
