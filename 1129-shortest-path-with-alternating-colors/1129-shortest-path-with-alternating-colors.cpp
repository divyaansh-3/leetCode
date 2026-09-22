class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         vector<vector<pair<int,int>>> graph(n);

        for (auto edge : redEdges) {
            graph[edge[0]].push_back({edge[1], 0});
        }

        for (auto edge : blueEdges) {
            graph[edge[0]].push_back({edge[1], 1});
        }

        vector<int> answer(n, -1);

        vector<vector<bool>> visited(n, vector<bool>(2, false));

        queue<pair<int,int>> q;

        q.push({0, 0});
        q.push({0, 1});

        visited[0][0] = true;
        visited[0][1] = true;

        answer[0] = 0;

        int distance = 0;

        while (!q.empty()) {

            int size = q.size();
            distance++;

            while (size--) {

                int node = q.front().first;
                int lastColor = q.front().second;

                q.pop();

                for (auto edge : graph[node]) {

                    int nextNode = edge.first;
                    int nextColor = edge.second;

                    if (nextColor == lastColor)
                        continue;

                    if (visited[nextNode][nextColor])
                        continue;

                    visited[nextNode][nextColor] = true;

                    q.push({nextNode, nextColor});

                    if (answer[nextNode] == -1)
                        answer[nextNode] = distance;
                }
            }
        }

        return answer;
    }
};