class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
         const int INF = 1e9;
        vector<int> bestTime(numLaps + 1, INF);

        for (const auto& tire : tires) {
            int f = tire[0], r = tire[1];
            int time = 0, currentTime = f;
            for (int i = 1; i <= numLaps && time + currentTime < INF; ++i) {
                time += currentTime;
                bestTime[i] = min(bestTime[i], time);
                
                // If the current lap time exceeds INF or becomes unrealistic, stop
                if (currentTime >= INF / r) break;

                currentTime *= r;
            }
        }

        vector<int> dp(numLaps + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j] + bestTime[j] + (i == j ? 0 : changeTime));
            }
        }

        return dp[numLaps];
    }
};