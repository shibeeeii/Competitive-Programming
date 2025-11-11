#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &entry : mp)
        res.push_back(entry.second);

    return res;
}

int main() {
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> grouped = groupAnagrams(words);

    for (auto &group : grouped) {
        for (auto &word : group) cout << word << " ";
        cout << endl;
    }
    return 0;
}
