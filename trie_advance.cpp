// Trie for insertion, count_words_equal_to, count_words_starting_with and deletion

#include <bits/stdc++.h>
class Trie
{
    class TrieNode
    {
        TrieNode *links[26];
        int endsWith;
        int countPrefix;

    public:
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                links[i] = nullptr;
            }
            endsWith = 0;
            countPrefix = 0;
        }

        bool contains(char ch)
        {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, TrieNode *node)
        {
            links[ch - 'a'] = node;
        }

        TrieNode *get(char ch)
        {
            return links[ch - 'a'];
        }

        void setEnd()
        {
            endsWith += 1;
        }

        int countEnd()
        {
            return endsWith;
        }

        int countPrefixes()
        {
            return countPrefix;
        }

        void decreasePrefix()
        {
            countPrefix -= 1;
        }

        void decreaseEnd()
        {
            endsWith -= 1;
        }

        void setPrefix()
        {
            countPrefix += 1;
        }
    };

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;

        for (char ch : word)
        {
            if (!node->contains(ch))
            {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
            node->setPrefix();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->contains(ch))
                return 0;
            node = node->get(ch);
        }
        return node->countEnd();
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->contains(ch))
                return 0;
            node = node->get(ch);
        }
        return node->countPrefixes();
    }

    void erase(string &word)
    {
        TrieNode *node = root;
        vector<TrieNode *> path; // Keep track of nodes for correct prefix decrement
        path.push_back(node);

        for (char ch : word)
        {
            if (!node->contains(ch))
                return;
            node = node->get(ch);
            path.push_back(node);
        }

        node->decreaseEnd();

        for (int i = 1; i < path.size(); ++i)
        {
            path[i]->decreasePrefix();
        }
    }
};