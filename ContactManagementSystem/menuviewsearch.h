#pragma once
// removes warning

#ifndef MENUVIEWSEARCH_H
#define MENUVIEWSEARCH_H

void setIDSearchCriteria(struct contact *searchCriteria);

void setfnameCriteria(struct contact *searchCriteria);

void setlnameCriteria(struct contact *searchCriteria);

void setphoneCriteria(struct contact *searchCriteria);

void setemailCriteria(struct contact *searchCriteria);

void setcompanyCriteria(struct contact *searchCriteria);

void search(struct contact *searchCriteria, struct contact *listHead, struct contact *tmpListHead, struct contact *tmpListTail);

#endif