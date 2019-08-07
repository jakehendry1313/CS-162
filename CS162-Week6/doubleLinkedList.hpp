/**************************************************************************
** Program name: Lab 6  - doubleLinkedList.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This file will hold the prototypes for the functions that
**               will be implemented in the cpp file. There are two classes
**               called Node and LinkedList that will determine what the
**               user's input intended to be. 
****************************************************************************/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class Node
{
public:
     int val;
     Node* next;
     Node* prev;
};

class LinkedList
{
private:
     Node *head, *tail;
public:
     LinkedList();
     void addFront(int);
     void addBack(int);
     int deleteFront();
     int deleteBack();
     void traverseReverse();
     void traverseList();
     int getAtHead();
     int getAtTail();
};

#endif