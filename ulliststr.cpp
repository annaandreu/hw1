#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) { 
// CASE 1 : Array is empty
  if (empty()){ 
    Item* Node1 = new Item();
    Node1 -> val[Node1 -> first] = val; // first spot 
    Node1 -> last= Node1 -> last +1 ; // one after last used index 
    
    head_ = Node1;
    tail_ = Node1; 
  }
  // CASE 2: No room to push_back - create new node 
  else if ((tail_ -> last) > (ARRSIZE - 1) ){
    Item* Node2 = new Item(); // allocaate new var 
    tail_ -> next = Node2; // point to next item
    
    Node2 -> prev = tail_; // before node 2 comes tail (node1)
    //Node2 -> next = nullptr;
    tail_ = Node2; // Node2 becomes new tail_ 

	//assign first and last pointers
    tail_ -> first = 0;
		tail_ -> last = (tail_ -> first) +1; // one after 
		
		tail_ -> val[tail_ -> first] = val; 
    //tail_ -> val[tail_ -> last] = val; // val = last slot of tail_ node
		//tail_ -> last = (tail_ -> last) + 1; // update last index (1 after new val) 
  }
  //CASE 3: Room to push_back
  else{
    tail_ -> val[tail_ -> last] = val; // val = last in tail node 
		tail_ -> last = (tail_ -> last) + 1; // update last index (1 after new val) 
    //tail_ -> prev = head_; 
  }
size_++; 
}

void ULListStr::pop_back(){
  // array is empty- nothing 
	if (empty()){ 
    return; 
  }
  // one item in array
  else if (tail_ -> last == tail_ -> first +1){ 
      if(tail_-> prev == nullptr) { // ONLY one node 
        delete tail_;  
        head_ = nullptr;
        tail_ = nullptr;
        size_ =0;
        return;
      }
      else{ // MORE nodes
      tail_ = tail_-> prev; 
      delete tail_ -> next;
      tail_-> next = nullptr;
      }
    }
   //NORMAL - remove number from first index in array
  else {
  tail_ -> last = (tail_ -> last) - 1;
  }

  size_ --;  
}
  

void ULListStr::push_front(const std::string& val){
  // CASE 1: array is empty  
  if (empty()){ 
    Item* Node_1 = new Item();
    Node_1 -> first = ARRSIZE -1; // slot items at back of array
    Node_1 -> last = ARRSIZE;

    Node_1 -> val[Node_1 -> first] = val; // first spot 
    //Node_1 -> last= (Node_1 -> first) + 1; 
    
    head_ = Node_1;
    tail_ = Node_1;
  }
  // CASE 2: no room to push_front - create new node 
  else if (head_ -> first == 0){
    // allocate new item
    Item* Node_0 = new Item(); 
    
    // set pointers
    head_ -> prev = Node_0; // prev is Node_0 (new item)
    Node_0 -> next = head_; // next is head_ (old item)
    head_ = Node_0;  // make front the new head_

    head_ -> first = ARRSIZE -1; // first value = last slot 
    head_ -> last = ARRSIZE; // last is index before 
    
    head_ -> val[head_ -> first] = val; // set val to first 
  }
  // CASE 3- room to push_front
  else{ 
    head_ -> first = head_ -> first - 1; // update first location 
    head_ -> val[head_ -> first] = val; // add new val to first 
    //head_ -> next = tail_;
    
  }

size_++; 
 }

void ULListStr::pop_front(){
  if (head_ != NULL) { 
    if (!(empty())) { // list is not empty - MOST cases 
      head_-> first= head_-> first + 1;  // just move index 
      size_--;
    }
    
    // if only one item left
    if (head_-> first == head_-> last) {
      //ONLY node left 
      if (head_ == tail_) {
        Item* temp = head_;
        head_ = nullptr;
        tail_ = nullptr;
        delete temp;
      }
      //more than one node - more items in list 
      else {
        Item* temp = head_;
        head_ = head_->next;
        delete temp;
      }
    }
  }
 }

  std::string const & ULListStr::back() const{
    return tail_ -> val[(tail_ -> last) -1]; // return last value 
  }

  std::string const & ULListStr::front() const{
    return head_ -> val[(head_ -> first)]; // return first value 
  }

  std::string* ULListStr::getValAtLoc(size_t loc) const{
    Item* position = head_; 
		size_t loc_index = 0;

// while in range 
		while (loc >= 0 && loc < size_){
			// traverse all items in node 
			for (size_t i = (position -> first); i < (position -> last); i++) {
			if (loc == loc_index){ // if we reach the location's index 
				return &(position -> val[i]);
			}
			loc_index++; 
		}
		// if not in first node - move to next node
		position = position -> next;
		}
    if (loc > size_){
      return NULL;
    }
    if (size_ == 0){
      return NULL;
    }
	
  }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


// ListInsertBack.OneItemAdd