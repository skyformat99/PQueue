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


/* Something unclear here: say I have a:2, a:4, a:6 in my queue, what should
 * happen when I changePriority("a", 3)?
 */
void ArrayPriorityQueue::changePriority(string value, int newPriority) {
  int index = findIndex(value);
  if (index == -1) {
    error("Value does not exist in current queue");
  } else if (arr[index].priority < newPriority) {
    error("You are lowering priority for this value");
  } else {
    arr[index].priority = newPriority;
  }
}

void ArrayPriorityQueue::clear() {
  count = 0;
}

string ArrayPriorityQueue::dequeue() {
  int index = 0;
  string result = "";
  if (size() == 0) {
    error("Empty queue!");
  } else {
    index = findTopPriorityIndex();
    result = arr[index].value;
    rearrangeArr(index);	// note count is decremented in reaarangeArr();
  }
  return result;
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
  int index = 0;
  if (size() == 0 ) {
    error("Empty queue!");
  } else {
    index = findTopPriorityIndex();
  }

  return arr[index].value;
}

int ArrayPriorityQueue::peekPriority() const {
  int index = 0;
  if (size() == 0 ) {
    error("Empty queue!");
  } else {
    index = findTopPriorityIndex();
  }

  return index;
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
int ArrayPriorityQueue::findIndex(string s) const {
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
int ArrayPriorityQueue::compareEntries(PQEntry one, PQEntry two) const {
  if (one.priority < two.priority) return -1;
  else if (one.priority > two.priority) return 1;
  else if (one.value < two.value) return -1;
  else if (one.value > two.value) return 1;
  else return 0;
}


/* Helper function, find the top priority entry in the queue and returns its index
 * If there are multiple top priority entries, returns the index of the first one
 */
int ArrayPriorityQueue::findTopPriorityIndex() const {
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


/* Helper function, rearranges the array in the following way:
 * removes the entry at index, move all the entries after index up to fill the gap
 * what about count? 
 */
void ArrayPriorityQueue::rearrangeArr(int index) {
  for (int i = index + 1; i < count; i++) {
    arr[i - 1] = arr[i];
  }
  count--;			// be careful here, don't do it twice
}
