#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(nLog(n)) time | O(1) space
int minimumWaitingTime(vector<int> queries) {
    sort(queries.begin(), queries.end());// O(nLog(n)) time
    int totalWaitingTime = 0;
    for(int i = 0; i < queries.size(); i++) {// O(n) time
        int duration = queries[i];
        int queriesLeft = queries.size() - (i + 1);
        totalWaitingTime += duration * queriesLeft;
    }
    return totalWaitingTime;
}

int main() {
    vector<int> queries = {3, 2, 1, 2, 6};
    int expected = 17;
    cout << minimumWaitingTime(queries);
    return 0;
}
