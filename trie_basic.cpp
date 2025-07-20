// Trie for insertion, search, prefix count

class Trie
{
public:
    class TrieNode
    {
    public:
        TrieNode *links[26];
        bool flag; // flag == true means this is the end

        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                links[i] = nullptr;
            }
            flag = false;
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
            flag = true;
        }

        bool isEnd()
        {
            return flag;
        }
    };

    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!(node->contains(ch)))
            {
                node->put(ch, new TrieNode());
            }

            node = node->links[ch - 'a'];
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->contains(ch))
                return false;
            node = node->links[ch - 'a'];
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (!node->contains(ch))
                return false;
            node = node->links[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */