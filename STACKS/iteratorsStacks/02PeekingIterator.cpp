/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int peekElem;
    bool isPeekPresent;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        isPeekPresent = false;
        peekElem = -1;
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (isPeekPresent) {
            return peekElem;
        }
        peekElem = Iterator::next();
        isPeekPresent = 1;
        return peekElem;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (isPeekPresent) {
            isPeekPresent = 0; 
            return peekElem;
        }
        
        return Iterator::next();
	}
	
	bool hasNext() const {
	    if (isPeekPresent)
            return 1;
        return Iterator::hasNext();

	}
};