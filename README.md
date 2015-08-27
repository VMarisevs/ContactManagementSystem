# ContactManagementSystem
	by Vladislavs Marisevs

# GMIT Software Development year 2
Lecturer: Damien Costello
Submission Date: April 28th 2014

# About
This is contact management system developed using C and shows the knowledge of linked lists, sorting techniques and data encryption.
Using this application user can save his contact list into .csv file and encrypt it. There are few options to add, edit or delete contacts. Also contacts can be sorted by any of the field and can be found using search option.
Application has a basic command prompt interface, user can choose the option by pressing "Enter" and navigate using up or down arrow key.

# IDE 
-	Application was made using Microsoft Visual Studio 2010
	
# Menu helper
----------------------------------------------------------------------						
	File => Load	
					loading csv file,
					-	reading file name, (if not entered uses default.csv)
					-	Ignoring first line, each line is new structure in doubly linked list. Last line contains recent auto increment value and list size.
					-	Identifies if it is encrypted or not.
					
					
			Save	
					-	Saves the list into file without encryption.
					
			Save As
					
					-	Reading new file name, and save as csv file
					

			Save Encrypted
			
					-	Creates new encrypted file. The encryption key is initialized in global.c and encrypting function is in menufile.c
			
---------------------------------------------------------------------

	Edit =>	Add
			
					-	Inserting new node into list, and increasing the size and autoinc value. 
					-	Autoinc is saved in doubly linked list head and size in tail node.
			
			Edit
			
					-	Selecting a node by id, values will be changed only if they are entered.
			
			Remove
			
					-	Removes node by id. (Also updating size)
			
---------------------------------------------------------------------

	View => Print
			
					-	Print the main doubly linked list.
			
			Sort	=> Id, Name, Surname, Phone, Email, Company				
			
					-	User can sort list in ascending sequence by id, name, surname phone, email or company. Selection sort is implemented using temporary doubly linked list, and after copied back into list.
					
			Search	=>	
			
					-	User can search for a node using id, in this case it will return 0 or 1 record. 
					-	Also user can "clear" the searching structure.
					-	If user want to find a record list, he must specify requirements and hit search.
					-	Search is case sensitive.