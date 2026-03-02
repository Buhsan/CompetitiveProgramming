#include <bits/stdc++.h>

using namespace std;

struct Node{
  char val;
  Node* prev;
  Node* next;

  Node(char c) : val(c), prev(nullptr), next(nullptr) {}
  Node(char c, Node* p, Node* n) : val(c), prev(p), next(n) {}
};

struct LinkedList {
  int size;
  Node* head;
  Node* tail;
  Node* cursor;

  LinkedList() : size(0), head(nullptr), tail(nullptr), cursor(nullptr) {}

  void addChar (char c) {
    Node* newNode = new Node(c);
    if (!head) {
      head = newNode;
      tail = head;
      cursor = head;
      size++;
      return;
    }

    if (cursor == nullptr) { // at the head
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    } else if (cursor == tail) { // at the tail
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    } else { // middle case
      newNode->prev = cursor;
      if (cursor->next) {
        cursor->next->prev = newNode;
        newNode->next = cursor->next;
      }
      cursor->next = newNode;
    }
    cursor = newNode;
    size++;
  }


  void deleteChar() { // delete on the right
    if (!head || cursor == tail) return;

    if (cursor == nullptr) { // at the head
      Node* aux = head;
      head = head->next;
      if (head) {
        head->prev = nullptr;
      } else {
        tail = nullptr;
      }
      delete aux;
    } else {  // middle case
      Node* aux = cursor->next;
      cursor->next = aux->next;
      if (aux->next) aux->next->prev = cursor;
      else {
        tail = cursor;
      }
      delete aux;
    }
    size--;
  }

  void moveRight() {
    if (!head || cursor == tail) return;
    if (cursor == nullptr) {
      cursor = head;
    } else {
      cursor = cursor->next;
    }
  }


  void init() {
    cursor = nullptr;
  }

  void fin() {
    cursor = tail;
  }
};



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while (getline(cin,s)) {
    // -: init
    // *: move right
    // +: fin
    // 3: delete on the right
    // deque<char> dq;
    LinkedList linked;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '-') {
        linked.init();
      } else if (s[i] == '*') {
        linked.moveRight();
      } else if (s[i] == '+') {
        linked.fin();
      } else if (s[i] == '3') {
        linked.deleteChar();
      } else {
        // cout << "enter" << endl;
        linked.addChar(s[i]);
      }
      // Node* curr = linked.head;
      // while (curr) {
      //   cout << curr->val;
      //   curr = curr->next;
      // }
      // cout << endl;
    }

    Node* curr = linked.head;
    while (curr) {
      cout << curr->val;
      curr = curr->next;
    }
    cout << '\n';
  }
  return 0;
}
