#pragma once
// removes warning

#ifndef MENUEDIT_H
#define MENUEDIT_H

void insertNewContact(struct contact *headContact, struct contact *tailContact);

void editContact(struct contact *headContact);

void removeContact( struct contact *tailContact);


#endif