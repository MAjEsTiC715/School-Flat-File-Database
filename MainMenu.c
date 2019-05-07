#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StructLinkedList.h"

void clear_buffer() { while( getchar() != '\n' ) {} }
int ClassID = 1;
int AssignmentID = 1;
void add_menu()
{
	
	int choice;
	printf( "Add Menu\n" );
	printf( "1. Add Student\n" );
	printf( "2. Add Class\n" );
	printf( "3. Add Assignment\n" );
	printf( "4. Add Grade\n" );
	printf( "5. Enroll Student\n" );
	printf( "6. Return to Main Menu\n" );

	printf( "Please enter 1-6: " );

	scanf( "%d", &choice );

	clear_buffer();

	char tempF[30];
	char tempL[30];
	char tempS[9];
	char temp[30];
	char tempAssName[30];
	char tempSSN[9];
	int  tempPoints;
	int  tempClassID;
	int  tempAssID;
	int i;
	switch( choice )
	{
		case 1:
			
			printf( "Enter First Name: ");
			scanf("%s", &(tempF[30]));
			printf( "Enter Last Name: " );
			scanf("%s", &(tempL[30]));
			printf( "Enter SSN: " );
			scanf("%s", &(tempS[9]));

			add_student_node(&student_list, &tempF[30], &tempL[30], &tempS[9]);
			break;
		case 2:
			printf( "Enter Class Name: " );
			scanf("%s", &(temp[30]));
			add_class_node(&class_list, ClassID, &temp[30]);
			ClassID += 1;
			break;
		case 3:
			printf( "Enter Class ID (-1 for class list): " );
			scanf("%d", &tempClassID);
			if (tempClassID == -1) {
				print_nodes(&class_list, 2);
				break;
			}
			i = search_ClassID(&class_list, tempClassID);
			if (i == 0) {
				printf("No Class Found");
				break;
			}
			printf( "Enter Assignment Name: " );
			scanf("%s", &(tempAssName[30]));
			printf( "Enter Point Value: " );
			scanf("%d", &tempPoints);
			add_assignments_node(&assignments_list, AssignmentID, &tempAssName[30], tempPoints, tempClassID);
			AssignmentID += 1;
			break;
		case 4:
			printf( "Enter AssignmentID: " );
			scanf("%d", &tempAssID);
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN[9]));
			printf( "Enter Points: " );
			scanf("%d", &tempPoints);
			break;
		case 5:
			printf( "Enrolling Student" );
			break;
		case 6:
			return;
		default:
			printf( "What???" );
			break;
		}

	add_menu();
}

void edit_menu()
{
	int choice;
	printf( "Edit Menu\n" );
	printf( "1. Edit Student\n" );
	printf( "2. Edit Class\n" );
	printf( "3. Edit Assignment\n" );
	printf( "4. Edit Grade\n" );
	printf( "5. Return to Main Menu\n" );

	printf( "Please enter 1-5: " );

	scanf( "%d", &choice );

	clear_buffer();

	switch( choice )
	{
		case 1:
			printf( "Editing Student" );
			break;
		case 2:
			printf( "Editing Class" );
			break;
		case 3:
			printf( "Editing Assignment" );
			break;
		case 4:
			printf( "Editing Grade" );
			break;
		case 5:
			return;
		default:
			printf( "What???" );
			break;
	}

	edit_menu();
}

void delete_menu()
{
	int choice;
	printf( "Delete Menu\n" );
	printf( "1. Delete Student\n" );
	printf( "2. Delete Class\n" );
	printf( "3. Delete Assignment\n" );
	printf( "4. Delete Grade\n" );
	printf( "5. Drop Student");
	printf( "6. Return to Main Menu\n" );

	printf( "Please enter 1-6: " );

	scanf( "%d", &choice );

	clear_buffer();

	switch( choice )
	{
		case 1:
			printf( "Deleting Student" );
			break;
		case 2:
			printf( "Deleting Class" );
			break;
		case 3:
			printf( "Deleting Assignment" );
			break;
		case 4:
			printf( "Deleting Grade" );
			break;
		case 5:
			printf( "Dropping Student" );
			break;
		case 6:
			return;
		default:
			printf( "What???" );
			break;
	}

	delete_menu();
}

void view_data_grades_menu()
{
	int choice;
	printf( "View Grades Menu\n" );
	printf( "1. View Class Average Grade\n" );
	printf( "2.	View Student Average Grades\n" );
	printf( "3.	View Class Assignment Average Grades\n" );
	printf( "4.	View Class Assignment Grades\n" );
	printf( "5. Return to Main Menu\n" );

	printf( "Please enter 1-5: " );

	scanf( "%d", &choice );

	clear_buffer();

	switch( choice )
	{
		case 1:
			printf( "Viewing Student" );
			break;
		case 2:
			printf( "Viewing Class" );
			break;
		case 3:
			printf( "Viewing Assignment" );
			break;
		case 4:
			printf( "Viewing Grade" );
			break;
		case 5:
			printf( "Viewing Enrollment" );
			break;
		case 6:
			return;
		default:
			printf( "What???" );
			break;
	}

	view_data_grades_menu();
}

void view_data_menu()
{
	int choice;
	printf( "View Data Menu\n" );
	printf( "1. View Student\n" );
	printf( "2. View Class\n" );
	printf( "3. View Assignment\n" );
	printf( "4. View Grades\n" );
	printf( "5. View Enrollment\n");
	printf( "6. Return to Main Menu\n" );

	printf( "Please enter 1-6: " );

	scanf( "%d", &choice );

	clear_buffer();

	switch( choice )
	{
		case 1:
			printf( "Viewing Student" );
			print_nodes(&student_list, 1);
			break;
		case 2:
			printf( "Viewing Class" );
			print_nodes(&class_list, 2);
			break;
		case 3:
			printf( "Viewing Assignment" );
			print_nodes(&assignments_list, 4);
			break;
		case 4:
			view_data_grades_menu();
			break;
		case 5:
			printf( "Viewing Enrollment" );
			print_nodes(&enrollment_list, 3);
			break;
		case 6:
			return;
		default:
			printf( "What???" );
			break;
	}

	view_data_menu();
}


void main_menu()
{
	int choice;
	printf( "Main Menu\n" );
	printf( "1. Add Data\n" );
	printf( "2. Edit Data\n" );
	printf( "3. Delete Data\n" );
	printf( "4. View Data\n" );
	printf( "5. Exit\n" );
	printf( "Please enter 1-5: " );

	scanf( "%d", &choice );
	
	clear_buffer();

	switch( choice )
	{
		case 1:
			add_menu();
			break;
		case 2:
			edit_menu();
			break;
		case 3:
			delete_menu();
			break;
		case 4:
			view_data_menu();
			break;
		case 5: //Exiting
			return;
		default:
			printf( "What???\n" );
			break;
	}

	main_menu();
}

int main()
{
	main_menu();
	return 0;
}