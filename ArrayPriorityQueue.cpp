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


/* Helper function, compares two PQEntry to see which is more important
 * Comparison rule: the one with smaller priority number is more important
 * If priority numbers are the same, then do a string comparison on value
 * the "smaller" string is more important.
 * Results: return -1 if one is more important, 1 otherwise
 * return 0 if the two are the same in terms of priority
 */
int ArrayPriorityQueue::compareEntries(PQEntry one, PQEntry two) {
  if (one.priority < two.priority) return -1;
  else if (one.priority > two.priority) return 1;
  else if (one.value < two.value) return -1;
  else if (one.value > two.value) return 1;
  else return 0;
}


/* Helper function, find the top priority entry in the queue and returns its index
 * If there are multiple top priority entries, returns the index of the first one
 */
int ArrayPriorityQueue::findTopPriorityIndex() {
  int index = 0;
  PQEntry current = arr[0];
  for (int i = 0; i < count; i++) {
    if (compareEntries(arr[i], current) == -1) { // arr[i] is more important
      index = i;
      current = arr[i];
    }  
  }
  return index;
}
