/* Unsorted array implementation of PQueue
 * Rui Hu
 */

#include "ArrayPriorityQueue.h"


/* ArrayPriorityQueue constructor */
ArrayPriorityQueue::ArrayPriorityQueue() {
  capacity = INITIAL_CAPACITY;
  arr = new PQEntry[capacity];
  count = 0;
}


/* Destructor */
ArrayPriorityQueue::~ArrayPriorityQueue() {
  delete[] arr;
}


void ArrayPriorityQueue::changePriority(string value, int newPriority) {
  // TODO: implement

}

void ArrayPriorityQueue::clear() {
  count = 0;
}

string ArrayPriorityQueue::dequeue() {
  // TODO: implement
  return "";   // remove this
}

/* enqueue() builds a new element with given value and priority
 * first then adds it to end of array
 */
void ArrayPriorityQueue::enqueue(string value, int priority) {
  if (count == capacity) {	// make sure has enough room
    doubleCapacity();
  }
  PQEntry current;
  current.value = value;
  current.priority = priority;
  arr[count++] = current;
}

bool ArrayPriorityQueue::isEmpty() const {
  return count == 0;
}

string ArrayPriorityQueue::peek() const {
  // TODO: implement
  return "";   // remove this
}

int ArrayPriorityQueue::peekPriority() const {
  // TODO: implement
  return 0;   // remove this
}

int ArrayPriorityQueue::size() const {
  return count;
}


/* I don't know the syntax for writing this */
ostream& operator<<(ostream& out, const ArrayPriorityQueue& queue) {
  return out;
}

/* Temp replacement for ostream operator until I figure out the index */
void ArrayPriorityQueue::printPQueue() {
  for (int i = 0; i < count; i++) {
    cout << arr[i].value << ":" << arr[i].priority << endl;
  }
}


/* doubleCapacity() allocates a new array in heap with twice the size of 
 * current array, copy all the elements from current to new, and make
 * arr point to the new array
 */
void ArrayPriorityQueue::doubleCapacity() {
  PQEntry *oldArr = arr;
  capacity *= 2;
  arr = new PQEntry[capacity];
  for (int i = 0; i < count; i++) {
    arr[i] = oldArr[i];
  }
  delete[] oldArr;
}


/* Helper function, findIndex returns the index of first 
 * appearance of value
 */
int ArrayPriorityQueue::findIndex(string s) {
  int index = -1;
  for (int i = 0; i < count; i++) {
    if (arr[i].value == s) {
      index = i;
      break;			// only need the first appearance
    }
  }
  return index;
}
