//
// Created by colin on 2018-12-15.
//

#include "leetcode.h"


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res;
        //https://en.cppreference.com/w/cpp/algorithm/transform
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        unordered_set<string> ban(banned.begin(), banned.end());
        vector<string> words;
        unordered_map<string, int> freq;

        bool next_islower = false, pre_islower = false;
        int b = 0, e = 0;
        int max_cnt = 0;
        for (int i = 0; i < paragraph.size(); i++) {
            next_islower = islower(paragraph[i + 1]);
            if (islower(paragraph[i])) {
                if (!pre_islower) {
                    b = i;
                }
                if (!next_islower) {
                    e = i + 1;
                    string word = paragraph.substr(b, e - b);
                    if (ban.find(word) == ban.end()) {
                        freq[word] += 1;
                        if (freq[word] > max_cnt) {
                            max_cnt = freq[word];
                            res = word;
                        }
                    }
                }
                pre_islower = true;
            } else {
                pre_islower = false;
            }
        }
        return res;
    }
};

int main() {
    vector<string> v1 = {"hit"};
    auto ret = Solution().mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v1);
    cout << ret << endl;
}

