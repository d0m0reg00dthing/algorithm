// http://www.spoj.com/problems/MST/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define MAX 10002

const int INF = 1e9;
vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];

struct option {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		return a.second > b.second;
	}
};

void Prims(int src) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> pq;
	pq.push(make_pair(src, 0));
	dist[src] = 0;
	while (!pq.empty()) {
		int u = pq.top().first;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && dist[v] > w) {
				dist[v] = w;
				pq.push(make_pair(v, w));
				//path[v] = u;
			} // end for
		} // end while
	}
}

int main() {
	int V, E;
	int u, v, w;

	cin >> V >> E;
	//memset(path, -1, sizeof(path));
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	int s = 1;
	Prims(s);

	// output
	long long int sum = 0;
	for (int i = 1; i <= V; i++) {
		sum += dist[i];
	}
	cout << sum << endl;

	return 0;
}
