#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menufile.h"
#include "global.h"
#include "contacts.h"
#include "printstring.h"

void crypt(char linx[])
{
	int i = 0;
	while (linx[i] != '\0')
	{
		//linx[i] ^= 12;
		linx[i] ^= secretkey[(i%8)];
		
		i++;
	}
}

int saveFile (struct contact *contactListHead,  struct contact *contactListTail, int encrypting)
{
	struct contact *currentContact;
	FILE *fp;
	char encryptedLine[LINEMAXCOUNT];
	int autoincrement = contactListHead->idNum,
		size = contactListTail->idNum;
	fp = fopen(fileName, "w");

	if (fp != NULL)
	{

		sprintf(encryptedLine,"Id, Name, Surname,  Phone, Email, Company");

		if (encrypting == 1)
			{
				crypt(encryptedLine);
			}

		fprintf(fp, "%s",encryptedLine);
	
		// starting from first record, not head node
		currentContact = contactListHead->next;

		while (currentContact->next != NULL)
		{

			// concatenate string 
			sprintf(encryptedLine,"%i, %s, %s, %s, %s, %s",
				currentContact->idNum,
				currentContact->firstName,
				currentContact->lastName,				
				currentContact->phoneNumber,
				currentContact->email,
				currentContact->company);

			if (encrypting == 1)
			{
				crypt(encryptedLine);
			}

			// writing line into file
			fprintf(fp, "\n%s",encryptedLine);

			currentContact = currentContact->next;
		}

		size = currentContact->idNum;

		// concatenate string 
		sprintf(encryptedLine,"autoincrement = %i, size = %i", autoincrement, size);

		if (encrypting == 1)
		{
			crypt(encryptedLine);
		}

		// writing line into file
		fprintf(fp, "\n%s",encryptedLine);

		fclose(fp);

		// return true if the file is writable
		return 1;
	}

	return 0;
}

int saveAsFile (struct contact *contactListHead,  struct contact *contactListTail, int encrypting)
{
	char  fname[MAXSTRLENGTH];

	setCursorPosition(40,4); printColouredText("File Name(empty=default):", 2);
	fflush(stdin);
	gets_s(fname ,MAXSTRLENGTH);

	if (strlen(fname) > 0)
	{
		strcpy(fileName, fname);
	}

	if (saveFile(contactListHead, contactListTail, encrypting))
	{
		return 1;
	}

	return 0;
}

int readFiles(struct contact *contactListHead,  struct contact *contactListTail)
{
	struct contact *newContact;
	FILE *fp;
	char line[LINEMAXCOUNT], fname[MAXSTRLENGTH], tmpstr[LINEMAXCOUNT];
	int encrypted = 0;

	setCursorPosition(40,4); printColouredText("File Name(default.csv):", 2);
	fflush(stdin);
	gets_s(fname ,MAXSTRLENGTH);
	
	
	if (strlen(fname) > 0)
	{
		strcpy(fileName, fname);
	}


	fp = fopen(fileName, "r");

	if (fp != NULL)
	{
		fgets(line,LINEMAXCOUNT, fp);
	
		// verifying if the readable file is encrypted or not
		if (strstr(line,"Id, Name, Surname,  Phone, Email, Company") != 0)
			{
				encrypted = 0;
			} else
			{
				encrypted = 1;
			}

		while(fgets(line, LINEMAXCOUNT, fp) != NULL)
		{

			

			// swaps new line to empty char
			if (line[strlen(line)-1] == '\n') 
			{
				line[strlen(line)-1] = '\0';
			}

			// decrypting
			if (encrypted == 1)
			{
				crypt(line);
			}


			if (strstr(line,"autoincrement") == 0)
			{
				newContact = (struct contact *)malloc(sizeof(struct contact));
				clearContact(newContact);
		
				newContact->idNum = atoi(strtok(line,","));

				strcpy(tmpstr, strtok(NULL, ",")+1);
				if (strlen(tmpstr)>1)
				{
					strcpy(newContact->firstName, tmpstr);
				}

				strcpy(tmpstr, strtok(NULL, ",")+1);
				if (strlen(tmpstr)>1)
				{
					strcpy(newContact->lastName, tmpstr);
				}			
					
				strcpy(tmpstr, strtok(NULL, ",")+1);
				if (strlen(tmpstr)>1)
				{
					strcpy(newContact->phoneNumber, tmpstr);
				}

				strcpy(tmpstr, strtok(NULL, ",")+1);
				if (strlen(tmpstr)>1)
				{
					strcpy(newContact->email, tmpstr);
				}

				strcpy(tmpstr, strtok(NULL, ",")+1);
				if (strlen(tmpstr)>1)
				{
					strcpy(newContact->company, tmpstr);
				}

				// adding new record into list

				insertContact(contactListHead, contactListTail, newContact);
			} else
			{
					strtok(line," =");			
					contactListHead->idNum = atoi(strtok(NULL, " = "));
					strtok(NULL, " =");
					contactListTail->idNum = atoi(strtok(NULL, " = "));
			}
		

		}

	

		fclose(fp);
		return 1;
	}

	return 0;
}