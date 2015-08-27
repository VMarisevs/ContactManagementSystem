#pragma once
// removes warning

#ifndef MENUFILE_H
#define MENUFILE_H

// 4 -> size for id column + maxstrlen * 5 (columns)
#define LINEMAXCOUNT 4+MAXSTRLENGTH*5

void crypt(char linx[]);

int saveFile (struct contact *contactListHead,  struct contact *contactListTail, int encrypting);

int saveAsFile (struct contact *contactListHead,  struct contact *contactListTail, int encrypting);

int readFiles(struct contact *contactListHead,  struct contact *contactListTail);

#endif