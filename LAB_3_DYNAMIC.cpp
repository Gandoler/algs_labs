#include <stdio.h>
#include <limits.h>
#include <iostream>

#define V 7 // Количество вершин в графе

// Функция для нахождения минимума двух чисел
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Функция для нахождения кратчайшего пути от источника до всех вершин графа
void shortestPath(int graph[V][V], int source) {
    int dist[V]; // Массив для хранения длин кратчайших путей
    // Массив для хранения факта посещения вершины
    int visited[V];
    // Инициализация всех расстояний как "бесконечность", а факта посещения - как "не посещена"
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    // Расстояние от источника до самого себя равно 0
    dist[source] = 0;

    // Находим кратчайшие пути от источника до всех вершин
    for (int count = 0; count < V - 1; count++) {
        // Выбираем вершину с минимальным расстоянием от источника, которая еще не была посещена
        int u, minDist = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        // Помечаем вершину u как посещенную
        visited[u] = 1;
        // Обновляем расстояния к соседним вершинам вершины u
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Выводим кратчайшие пути от источника до всех вершин
    printf("Кратчайшие расстояния от вершины %d:\n", source);
    for (int i = 0; i < V; i++) {
        printf("Вершина %d -> Расстояние = %d\n", i, dist[i]);
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
    int source = 0; // Источник

    shortestPath(graph, source); // Находим кратчайшие пути от источника

    return 0;
}
