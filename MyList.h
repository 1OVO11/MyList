#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <iterator>
#include <string>
using namespace std;

struct Node {
  string data;
  Node *prev;
  Node *next;

  Node(string val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

template <class T> struct ListIterator {
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using difference_type = ptrdiff_t;
  using iterator_category = bidirectional_iterator_tag;

  Node<T> *cur;

  ListIterator(Node<T> *p = nullptr) : cur(p) {}

  reference operator*() const { return cur->data; }

  pointer operator->() const { return &(cur->data); }

  ListIterator &operator++() {
    cur = cur->next;
    return *this;
  }

  ListIterator &operator--() {
    cur = cur->prev;
    return *this;
  }

  ListIterator operator++(int) {
    ListIterator tem = *this;
    cur = cur->next;
    return tem;
  }

  ListIterator operator--(int) {
    ListIterator tem = *this;
    cur = cur->prev;
    return tem;
  }

  bool operator==(const ListIterator &other) const { return cur == other.cur; }

  bool operator!=(const ListIterator &other) const { return cur != other.cur; }
};

template <class T> class MyList {
private:
  Node<T> *head;
  int size;

public:
  using iterator = ListIterator<T>;

  MyList() {
    head = new Node<T>(T());
    head->next = head;
    head->prev = head;
    size = 0;
  }

  ~MyList() {
    clear();
    delete head;
  }

  void clear() {
    Node<T> *cur = head->next;
    while (cur != head) {
      Node<T> *del = cur;
      cur = cur->next;
      delete del;
    }
    head->next = head;
    head->prev = head;
    size = 0;
  }

  void push_back(const T &val) {
    Node<T> *newnode = new Node<T>(val);
    Node<T> *tail = head->prev;

    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;

    size++;
  }

  void pop_back() {
    if (size == 0)
      return;

    Node<T> *tail = head->prev;
    Node<T> *pre_tail = tail->prev;

    pre_tail->next = head;
    head->prev = pre_tail;

    delete tail;
    size--;
  }

  iterator begin() { return iterator(head->next); }
  iterator end() { return iterator(head); }

  int get_size() const { return size; }
  bool empty() const { return size == 0; }

  void show_list() {
    Node<T> *cur = head->next;
    while (cur != head) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << endl;
  }
};

#endif
