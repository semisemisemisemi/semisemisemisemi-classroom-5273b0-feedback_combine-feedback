#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> nodeDistance; // 벡터 이름 변경

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    nodeDistance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (int i : graph[current]) {
            if (!visited[i]) {
                visited[i] = true;
                nodeDistance[i] = nodeDistance[current] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    // n: 노드 수, m: 엣지 수
    int n, m, u, v, t1, t2;

    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);
    nodeDistance.resize(n, -1); // 새로운 이름 사용

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> t1 >> t2; // 최단 경로를 찾을 두 노드 입력

    bfs(t1);

    cout << nodeDistance[t2] << endl; // 새로운 이름 사용

    return 0;
}
