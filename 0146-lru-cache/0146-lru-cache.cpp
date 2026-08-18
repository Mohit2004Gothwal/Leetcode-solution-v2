class LRUCache {
private: 
   struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k,int v):key(k),value(v),prev(NULL),next(NULL){}
   };
   int capacity;
   unordered_map<int,Node*>cache;
   Node* head;
   Node* tail;

   void remove(Node* node){
     Node* prevNode = node->prev;
     Node* nextNode = node->next;
     prevNode->next = nextNode;
     nextNode->prev = prevNode;
   }
   void addToHead(Node* node){
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next=node;

   }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
     ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    int get(int key) {
        if(cache.find(key) == cache.end())return -1;
        Node* node = cache[key];
        remove(node);
        addToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end()){
        Node* node = cache[key];
        node->value =value;
        remove(node);
        addToHead(node);
        }else{
            if(cache.size()>=capacity){
                Node* lruNode = tail->prev;
                remove(lruNode);
                cache.erase(lruNode->key);
                delete lruNode;
            }
            Node* newNode = new Node(key,value);
            cache[key] = newNode;
            addToHead(newNode);
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */