//============================================================================
// Name        : dijkstra.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : an algorithm for finding the shortest paths between nodes in
//               a graph, which may represent, for example, road networks in
//               C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <climits>
#include <stack>

using namespace std;

#define FRI(i, a, b)      for(i = a; i < (int)b; ++i)

#define SOURCE            0
#define DESTINATION       8
#define SIZE              9

int graph[][SIZE] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} };

int dijkstra(int graph[][SIZE], int size, int src, int des) {
  int index, current;
  int minimal[size];
  stack<int> store = stack<int>();

  fill(minimal, minimal + size, INT_MAX);
  minimal[src] = 0;
  store.push(src);

  while (!store.empty()) {
    current = store.top();
    store.pop();

    FRI (index, 0, size) {
      if (graph[current][index] != 0 && current != index) {
        if (minimal[index] > minimal[current] + graph[current][index]) {
          minimal[index] = minimal[current] + graph[current][index];
          if (index != des) {
            store.push(index);
          }
        }
      }
    }
  }

  return minimal[des];
}

int main() {
    int cost = dijkstra(graph, SIZE, SOURCE, DESTINATION);

    cout << "Dijkstra: shortest Distance from " << SOURCE << " to " << DESTINATION << " is " << cost << endl;
  return 0;
}
