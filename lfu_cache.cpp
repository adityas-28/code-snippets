class LFUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }

        void updateVal(int val)
        {
            this->val = val;
        }

        int getVal()
        {
            return this->val;
        }

        int getKey()
        {
            return this->key;
        }
    };

    class List
    {
    public:
        Node *head;
        Node *tail;

        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void insertAtStart(Node *node)
        {
            Node *temp = head->next;
            head->next = node;
            node->next = temp;
            temp->prev = node;
            node->prev = head;
        }

        void deleteNode(Node *node)
        {
            Node *back = node->prev;
            Node *front = node->next;

            back->next = front;
            front->prev = back;

            node->next = node->prev = nullptr;
        }

        bool containsNode()
        {
            return head->next != tail;
        }

        Node *deleteFromTail()
        {
            if (!containsNode())
                return nullptr;

            Node *last = tail->prev;
            Node *lastlast = last->prev;
            lastlast->next = tail;
            tail->prev = lastlast;
            last->next = last->prev = nullptr;
            return last; // Return the deleted node so we can clean up maps
        }
    };

    vector<List *> v;
    unordered_map<int, int> freqMap;
    unordered_map<int, Node *> location;
    int maxCap;
    int currCap;

    LFUCache(int capacity)
    {
        maxCap = capacity;
        currCap = 0;
        if (capacity > 0)
        {
            List *newList = new List();
            v.push_back(newList);
        }
    }

    int get(int key)
    {
        if (maxCap == 0 || freqMap.find(key) == freqMap.end())
        {
            return -1;
        }

        Node *node = location[key];
        int freq = freqMap[key];

        // Remove from current frequency list
        v[freq - 1]->deleteNode(node);
        freq++;

        // Ensure vector is large enough for new frequency
        while (v.size() < freq)
        {
            v.push_back(new List());
        }

        // Add to new frequency list
        v[freq - 1]->insertAtStart(node);
        freqMap[key] = freq;

        return node->getVal();
    }

    void put(int key, int val)
    {
        if (maxCap == 0)
            return;

        if (freqMap.find(key) != freqMap.end())
        {
            // Key already exists, update value and frequency
            Node *node = location[key];
            node->updateVal(val);
            int freq = freqMap[key];

            // Remove from current frequency list
            v[freq - 1]->deleteNode(node);
            freq++;
            freqMap[key] = freq; // update new freq in freqMap

            // Ensure vector is large enough for new frequency
            while (v.size() < freq)
            {
                v.push_back(new List());
            }

            // Add to new frequency list
            v[freq - 1]->insertAtStart(node);
        }
        else
        {
            // create new node, and update its Location and freqMap
            Node *node = new Node(key, val);
            location[key] = node;
            freqMap[key] = 1;

            if (currCap < maxCap)
            {
                currCap++;
            }
            else
            {
                // delete from least frequeny list (if multiple, then least recent)
                int i = 0;
                while (i < v.size() && !v[i]->containsNode())
                { // checking from start the 1st non empty list
                    i++;
                }

                if (i < v.size())
                {
                    Node *deletedNode = v[i]->deleteFromTail();
                    if (deletedNode)
                    {
                        int deletedKey = deletedNode->getKey();
                        freqMap.erase(deletedKey);
                        location.erase(deletedKey);
                        delete deletedNode;
                    }
                }
            }

            // Ensure list containing frequency 1 elements exists
            if (v.empty())
            {
                v.push_back(new List());
            }

            v[0]->insertAtStart(node); // insert new node at freq1 start
        }
    }
};