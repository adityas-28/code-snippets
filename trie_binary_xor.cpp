// Trie for max/min XOR

class Trie {
    class TrieNode {
    public:
        TrieNode* links[2]; 
        TrieNode() {
            links[0] = nullptr;
            links[1] = nullptr;
        }
        bool contains(int bit) {
            return links[bit] != nullptr;
        }
        void put(int bit, TrieNode* node) {
            links[bit] = node;
        }
        TrieNode* get(int bit) {
            return links[bit];
        }
    };

public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->contains(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    // Find max XOR with num
    int findMax(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int complement = 1 - bit;

            if (node->contains(complement)) {
                maxXor |= (1 << i); 
                node = node->get(complement);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};


class Trie
{
    class TrieNode
    {
        TrieNode *links[2]; // 0 or 1 (binary)
    public:
        TrieNode()
        {
            links[0] = nullptr;
            links[1] = nullptr;
        }

        bool contains(char i)
        {
            return links[i - '0'] != nullptr;
        }

        void put(char i, TrieNode *node)
        {
            links[i - '0'] = node;
        }

        TrieNode *get(char i)
        {
            return links[i - '0'];
        }
    };

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int ch)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            char c = ((ch >> i) & 1) + '0';

            if (!node->contains(c))
                node->put(c, new TrieNode());
            node = node->get(c);
        }
    }

    int findMax(int ch)
    {
        TrieNode *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            char c = ((ch >> i) & 1) + '0';

            char complement = (c == '0') ? '1' : '0';

            if (node->contains(complement))
            {
                maxNum |= (1 << i); // since complement found, so set the i th bit
                node = node->get(complement);
            }
            else
            {
                node = node->get(c);
            }
        }

        return maxNum;
    }
};