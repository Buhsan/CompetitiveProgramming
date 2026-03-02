#include <bits/stdc++.h>

using namespace std;

struct Node{
  int n;
  Node* next;

  Node (int num) : n(num), next(nullptr) {};
};

struct CQueue {
  int size;
  Node* last;

  CQueue () : size(0), last(nullptr){}

  void addBack(int val) {
    Node* newNode = new Node (val);
    if (last && last->next) {
      newNode->next = last->next;
      last->next = newNode;
    }
    else if (last && size == 1) {
      last->next = newNode;
      newNode->next = last;
    }
    last = newNode;
    size++;
  }

  void deleteNode(Node* target, Node* prev) {
    if (!prev) return;
    if (size > 2) {
      prev->next = target->next;
    }
    target = nullptr;
    size--;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k && (n || k)) {
    CQueue q;
    for(int i = 1; i <= n; i++) {
      q.addBack(i);
    }

    // Node* previ = nullptr; 
    Node* start = q.last->next;
    // for (int i = 0; i < n; i++) {
    //   cout << start->n << " ";
    //   start = start->next;
    // }
    // cout << endl;
    // //
    // Node* next = start->next;
    // q.deleteNode(start, previ);
    //
    
    Node* prev = nullptr;
    while(q.size > 1) {
      for (int i = 0; i < k; i++) {
        prev = start;
        start = start->next;
        // cout << "start: " << start->n << endl;
      }
      q.deleteNode(start, prev);
      Node* startN = start->next;
      start = startN;
    }
    cout << start->n << '\n';


  }

  return 0;
}
