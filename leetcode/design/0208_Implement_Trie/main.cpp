//
// Created by colin on 2018-12-15.
//

//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
//
//示例:
//
//Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");
//trie.search("app");     // 返回 true
//说明:
//
//你可以假设所有的输入都是由小写字母 a-z 构成的。
//保证所有输入均为非空字符串。

#include "leetcode.h"

class Trie {
public:
    class Node {
        public:
            Node() {
                is_word_ = false;
            }
            Node* FindNext(char c) {
                if (next_.find(c) == next_.end()) {
                    return nullptr;
                }
                return next_[c];
            }
            void InsertNext(char c, Node* n) {
                next_.insert(make_pair(c, n));
            }
            bool IsWord() {
                return is_word_;
            }
            void SetWord() {
                is_word_ = true;
            }
        private:
            bool is_word_;
            unordered_map<char, Node*> next_;
    };

    /** Initialize your data structure here. */
    Trie() {
        root_ = new Node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0) return;
        Node* curr = root_;
        Node* next = nullptr;
        for (auto &c : word) {
            next = curr->FindNext(c);
            if (next == nullptr) {
                next = new Node();
                curr->InsertNext(c, next);
            }
            curr = next;
        }
        if (!curr->IsWord()) {
            curr->SetWord();
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.size() == 0) return false;
        Node* curr = root_;
        Node* next = nullptr;
        for (auto &c : word) {
            next = curr->FindNext(c);
            if (next == nullptr) {
                return false;
            }
            curr = next;
        }
        return curr->IsWord();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.size() == 0) return false;
        Node* curr = root_;
        Node* next = nullptr;
        for (auto &c : prefix) {
            next = curr->FindNext(c);
            if (next == nullptr) {
                return false;
            }
            curr = next;
        }
        return true;
    }

private:
    Node* root_;
};

class Trie2 {

private:
    struct Node{
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie2() {
        trie.clear();
        trie.push_back(Node());
    }

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        int treeID = 0;
        for (char c: word){
            if (trie[treeID].next.find(c) == trie[treeID].next.end()) {
                trie[treeID].next[c] = trie.size();
                trie.push_back(Node());
            }

            treeID = trie[treeID].next[c];
        }

        trie[treeID].end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word){
        int treeID = 0;
        for (char c: word) {
            if (trie[treeID].next.find(c) == trie[treeID].next.end())
                return false;

            treeID = trie[treeID].next[c];
        }
        return trie[treeID].end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {

        int treeID = 0;
        for (char c: prefix) {
            if (trie[treeID].next.find(c) == trie[treeID].next.end())
                return false;

            treeID = trie[treeID].next[c];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie;
    trie->insert("apple");
    cout << trie->search("appl");   // 返回 true
    cout << endl << trie->search("app");     // 返回 false
    cout << endl << trie->startsWith("app"); // 返回 true
    trie->insert("app");
    cout << endl <<  trie->search("app");     // 返回 true

}