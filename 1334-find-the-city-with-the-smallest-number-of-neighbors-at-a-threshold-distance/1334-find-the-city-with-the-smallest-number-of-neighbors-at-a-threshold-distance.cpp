class Solution {
public:
      vector<int> dijkstra(int src, int n,
                          vector<vector<pair<int,int>>>& graph) {

        const int INF = 1e9;

        vector<int> dist(n, INF);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            int currentDist = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if (currentDist > dist[u])
                continue;

            for (auto edge : graph[u]) {

                int v = edge.first;
                int weight = edge.second;

                if (currentDist + weight < dist[v]) {

                    dist[v] = currentDist + weight;

                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }


    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {

        vector<vector<pair<int,int>>> graph(n);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int answer = -1;
        int smallestCount = INT_MAX;

        for (int city = 0; city < n; city++) {

            vector<int> dist = dijkstra(city, n, graph);

            int count = 0;

            for (int i = 0; i < n; i++) {

                if (i != city &&
                    dist[i] <= distanceThreshold) {

                    count++;
                }
            }

            if (count <= smallestCount) {

                smallestCount = count;
                answer = city;
            }
        }

        return answer;
        
    }
};