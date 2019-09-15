class Solution {
public:
  int longestStrChain(vector<string>& words) {
    int ans = 0;
    unordered_map<int, vector<string>> nodes;
    unordered_map<string, int> memo;
    
    for (const auto &w : words) {
      nodes[w.size()].emplace_back(w);
    }
    
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
      auto &seeds = it->second;
      for (auto &s : seeds) {
        ans = max(ans, dfs(s, nodes, memo));
      }
    }
    
    return ans;
    
  }
  
  static int dfs(const string &w, unordered_map<int, vector<string>> nodes, unordered_map<string, int> memo) {
    if (memo.count(w)) return memo.at(w);
    
    int ans = 1;
    if (!nodes.count(w.size() + 1)) return ans;
    
    auto &candidates = nodes[w.size() + 1];
    for (const auto &c : candidates) {
      if (check(w, c)) 
        ans = max(ans, dfs(c, nodes, memo) + 1);
    }
    
    memo[w] = ans;
    
    return ans;
  }
  
  static bool check(const string &a, const string &b) {
    if (a.size() + 1 != b.size()) return false;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i++] != b[j++]) {
        i--;
        if (j - i > 1) return false;
      }
    }
    return true;
  }
};
