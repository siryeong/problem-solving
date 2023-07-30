#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0x0);
    cin.tie(0x0);
    cout.tie(0x0);

    int children, edges, threshold;
    cin >> children >> edges >> threshold;
    vector<int> graph[30001];

    int candy[30001];
    for (int i = 1; i <= children; i++) {
        cin >> candy[i];
    }

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<pair<int, int>> groups;
    bool visited[30001];
    memset(visited, 0, sizeof visited);

    for(int i = 1; i <= children; i++) {
        if(visited[i]) continue;

        int members = 0, candies = 0;
        queue<int> q; while(!q.empty()) q.pop();

        q.push(i);
        visited[i] = 1;
        members++;
        candies += candy[i];
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int j = 0; j < graph[cur].size(); j++) {
                int next = graph[cur][j];
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
                members++;
                candies += candy[next];
            }
        }

        groups.push_back({members, candies});
    }

    int dp[3001];
    memset(dp, 0, sizeof dp);
    sort(groups.begin(), groups.end());

    for(int i = 0; i < groups.size(); i++) {
        int members = groups[i].first;
        int candies = groups[i].second;
        for(int j = threshold-1; j >= members; j--) {
            dp[j] = max(dp[j-members] + candies, dp[j]);
        }
    }

    cout << dp[threshold-1] << "\n";
    return 0;
}
