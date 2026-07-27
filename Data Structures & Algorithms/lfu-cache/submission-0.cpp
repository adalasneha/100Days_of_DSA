class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
public:
    int cap;
    int currSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        cap = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node *node) {
        int freq = node->freq;

        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (currSize == cap) {
            List *list = freqList[minFreq];
            Node *node = list->tail->prev;

            list->removeNode(node);
            keyNode.erase(node->key);
            delete node;

            currSize--;
        }

        Node *newNode = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(newNode);
        keyNode[key] = newNode;

        currSize++;
    }
};