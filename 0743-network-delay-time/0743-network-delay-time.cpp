class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentDist > dist[u])
                continue;

            for (auto edge : adj[u]) {
                
                int v = edge.first;
                int weight = edge.second;

                if (currentDist + weight < dist[v]) {
                    dist[v] = currentDist + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            
            if (dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};