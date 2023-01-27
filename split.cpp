/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens) // *& can change value and address 
{
  Node* position = in; // create copy of in pointer to track current position and traverse list

  if (position == nullptr ){ // list is empty
    odds = nullptr;
    evens = nullptr;
    return; 
  }

  else if ((position -> value) % 2 == 0){ // if even 
    evens = position; // assign pos to even
    //cout << "even" << evens -> value << endl; 
    position = position -> next; // move down in position
    split(position, odds, evens -> next); 
    //recursively call again but moving down in 1 & odd 1 */
  }
  
  else { // if odd 
    odds = position;  
    //cout << "odds" << odds -> value << endl;
    position = position -> next;
    split(position, odds -> next, evens); 
  }
  in = nullptr;
}

/* If you needed a helper function, write it here */
