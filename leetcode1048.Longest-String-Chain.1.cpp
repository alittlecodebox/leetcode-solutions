class Solution {
public:
  int longestStrChain(vector<string>& words) {
    int n = words.size(), ans = 0;
    vector<int> mp[17];
    vector<int> f(n, 1);
    
    for (int i = 0; i < n; i++) {
      mp[words[i].size()].push_back(i);
    }
    
    for (int s = 2; s <= 16; s++) {
      for (auto i : mp[s]) {
        for (auto j : mp[s - 1]) {
          if (check(words[j], words[i]))
            f[i] = max(f[i], f[j] + 1);
        }
        
        ans = max(ans, f[i]);
      }
    }
    return ans;
  } 
  
  static bool check(const string &a, const string &b) {
    if (b.length() != a.length() + 1) return false;
    
    int i = 0, j = 0;
    while(i < a.length() && j < b.length()) {
      if (a[i] == b[j]) {
        i++;j++;
      } else {
        j++;
      }
    }
    
    return i == a.length();
  }
};
