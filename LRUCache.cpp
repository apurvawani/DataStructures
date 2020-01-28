/*
The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as 
follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the 
least recently used item before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Input Format:
The first line of input contain an integer T denoting the number of test cases. Then T test case follow. Each test case 
contains 3 lines. The first line of input contains an integer N denoting the capacity of the cache and then in the next line 
is an integer Q denoting the number of queries Then Q queries follow. A Query can be of two types -
1. SET x y : sets the value of the key x with value y
2. GET x : gets the key of x if present else returns -1.

Output Format:
For each test case, in a new line, output will be space separated values of the query.

Your Task:
This is a function problem. You only need to complete the provided functions.

Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= Q <= 100

Example :
Input:
2
2
2
SET 1 2 GET 1
2
7
SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1

Output:
2
5 -1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next,*pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = pre = NULL;
    }  
};

class LRUCache {
    private:
    static unordered_map<int,Node *> hsmap;
    static int capacity,count;
    static Node *head,*tail;
   
    public:
    LRUCache(int cap) {
        unordered_map <int , Node *> temp;
        hsmap = temp;
        capacity = cap;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        head->pre = NULL;
        tail->next = NULL;
        tail->pre = head;
        count = 0;
    }
  
    static void deleteNode(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
      
    static void addBegin(Node *node) {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }  
      
    static int get(int key) {
        if(hsmap.find(key) != hsmap.end()) {
            Node *node = hsmap.at(key);
            int result = node->value;
            deleteNode(node);
            addBegin(node);
            return result;
        }
        else
            return -1;
    }
    
    static void set(int key, int value) {
        if(hsmap.find(key) != hsmap.end()) {
            Node *node = hsmap.at(key);
            node->value = value;
            deleteNode(node);
            addBegin(node);
        }
        else {
            Node *node = new Node(key , value);
            hsmap.insert(make_pair(key , node));
            if(count < capacity) {
                count++;
                addBegin(node);
            }
            else {
                hsmap.erase(tail->pre->key);
                deleteNode(tail->pre);
                addBegin(node);
            }
        }
    }   
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int c , q;
        cin >> c >> q;
        LRUCache *cache = new LRUCache(c);
        while(q--) {
            string ip;
            cin >> ip;
            if(ip == "SET") {
                int key , val;
                cin >> key >> val;
                cache->set(key , val);
            }
            else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
