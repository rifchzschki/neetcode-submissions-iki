
class LinkedList{
    public:
    int key, val;
    LinkedList* next;
    LinkedList* prev;

    LinkedList(int key, int val): key(key), val(val), next(nullptr), prev(nullptr){};
};
class LRUCache {
private:
    void swapNodeToMRU(LinkedList* node){
        if(node==last) return;

        if(node==first){
            first = first->next;
            if(first) first->prev = nullptr;
        }else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = last;
        node->next = nullptr;
        last->next = node;
        last = node;
    }
public:
    int capacity;
    LinkedList* first;
    LinkedList* last;
    unordered_map<int, LinkedList*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        first = nullptr;
        last = nullptr;    
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            swapNodeToMRU(mp[key]);
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(first && last){
            if(mp.find(key)!=mp.end()){
                mp[key]->val = value;
            }else{
                if(!capacity){
                    mp.erase(first->key);
                    if(first==last){
                        delete first;
                    }else{
                        LinkedList* tmp = first->next;
                        LinkedList* tmp1 = first;
                        first = tmp;
                        first->prev = nullptr;
                        delete tmp1;
                    }
                    capacity++;
                }
                LinkedList* newNode = new LinkedList(key, value);
                mp[key]=newNode;
                LinkedList* tmp = last;
                tmp->next = newNode;
                newNode->prev = last;
                last = newNode;
                capacity--;
            }
            swapNodeToMRU(mp[key]);
        }else{
            first = last = new LinkedList(key, value);
            mp[key]=first;
            capacity--;
        }
    }
};
