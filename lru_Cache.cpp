class LRUCache
{
    class Node
    {
        int key;
        int val;

    public:
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

public:
    int cap = 0;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;

    void insertAfterHead(Node *node)
    { // insert node after head
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node *node)
    { // updates nodes orig location's back and front elements ptr
        Node *back = node->prev;
        Node *front = node->next;
        back->next = front;
        front->prev = back;
    }

    void deleteFromTail()
    {                                // deletes tail prev el
        Node *node = tail->prev;     // tail's prev
        Node *nodeBack = node->prev; // tail's prev prev

        map.erase(node->getKey()); // delete tail's prev from map

        nodeBack->next = tail;
        tail->prev = nodeBack;

        node->prev = node->next = nullptr;
        delete (node); // free memory
    }

    LRUCache(int capacity)
    {
        cap = capacity; // set maxCap
        // create a DLLL's head and tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *node = map[key];

            // update orig place's back and front elements ptr
            deleteNode(node);

            // insert node after head
            insertAfterHead(node);

            return node->getVal();
        }

        return -1;
    }

    void put(int key, int value)
    {
        Node *node;
        if (map.find(key) != map.end())
        {
            node = map[key];
            node->updateVal(value);
            deleteNode(node);
            insertAfterHead(node);
        }
        else
        {
            if (map.size() == cap)
            {
                deleteFromTail();
            }
            Node *node = new Node(key, value);
            insertAfterHead(node);
            map[key] = node;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
