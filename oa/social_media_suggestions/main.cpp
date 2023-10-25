#include "header.h"

vector<int> getRecommendedFriends(int numberOfUsers,
                                  const vector<pair<int, int>>& friendship) {
  vector<set<int>> friends(numberOfUsers);
  for (const auto& f : friendship) {
    friends[f.first].insert(f.second);
    friends[f.second].insert(f.first);
  }
  vector<vector<int>> commonFriends(numberOfUsers, vector<int>(numberOfUsers));

  for (int i = 0; i < numberOfUsers; i++) {
    for (int j = i + 1; j < numberOfUsers; j++) {
      if (friends[i].contains(j)) {
        continue;
      }
      set<int> inter;
      set_intersection(friends[i].begin(), friends[i].end(), friends[j].begin(),
                       friends[j].end(), inserter(inter, inter.end()));
      commonFriends[i][j] = inter.size();
      commonFriends[j][i] = inter.size();
    }
  }
  vector<int> results(numberOfUsers, -1);
  for (int i = 0; i < numberOfUsers; i++) {
    for (int j = i + 1; j < numberOfUsers; j++) {
      if (i == j) {
        continue;
      }
      if (commonFriends[i][j] > results[i]) {
        results[i] = j;
      }
      if (commonFriends[j][i] > results[j]) {
        results[j] = i;
      }
    }
  }
  return results;
}

int main() {
  vector<pair<int, int>> friendship{
      {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4},
  };

  auto result = getRecommendedFriends(5, friendship);
  for (const int recommendation : result) {
    cout << recommendation << ", ";
  }
  cout << "\n";
  return 0;
}
