#pragma once
// removes warning

#ifndef CONTACTS_H
#define CONTACTS_H

void clearContact(struct contact *currentContact); // wipes all information in current node

void clearContactList(struct contact *tailContact); // removes all elements from linked list, except head and tail

void copyContactList(struct contact *sourceHead,struct contact *sourceTail,struct contact *destinationHead,struct contact *destinationTail);

void addNewContact(struct contact *headContact, struct contact *tailContact, struct contact *currentContact); // inserting new node into list + autoincrement

void insertContact(struct contact *headContact, struct contact *tailContact, struct contact *currentContact); // inserting new node into list saving id

void copyContact(struct contact *sourceContact, struct contact *destinationContact); // copies whole structure of contact including id

int deleteLastContact(struct contact *tailContact); // removes last element in the list

int findDeleteContact(struct contact *tailContact, struct contact *deletedContact); // loops through list and removes element with selected id

int findEditContact(struct contact *headContact, struct contact *editedContact);

int compare(struct contact *firstContact, struct contact *secondContact, char compareBy);

#endif