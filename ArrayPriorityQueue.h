/* PQ Assignment
 * unsorted array implementation of priority queue
 * Rui Hu
 */

#ifndef _arraypriorityqueue_h
#define _arraypriorityqueue_h

#include <iostream>
#include <string>
#include "PQEntry.h"
#include "error.h"
using namespace std;

// TODO: comment
class ArrayPriorityQueue {
 public:
  ArrayPriorityQueue();
  ~ArrayPriorityQueue();
  void changePriority(string value, int newPriority);
  void clear();
  string dequeue();
  void enqueue(string value, int priority);
  bool isEmpty() const;
  string peek() const;
  int peekPriority() const;
  int size() const;
  void printPQueue();  
  friend ostream& operator <<(ostream& out, const ArrayPriorityQueue& queue);


 private:
  
  static const int INITIAL_CAPACITY = 10;

  /* Instance variables */
  PQEntry *arr;
  int capacity, count;

  /* Helper functions */
  void doubleCapacity();
  int findIndex(string s) const;  
  int compareEntries(PQEntry one, PQEntry two) const;
  int findTopPriorityIndex() const;
  void rearrangeArr(int index);
  
  /* need to deal with shallow copy here */

};

#endif
