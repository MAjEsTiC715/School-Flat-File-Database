#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StructLinkedList.h"
#include "add_menu.h"
#include "edit_menu.h"
#include "delete_menu.h"
#include "view_data_grades_menu.h"
#include "view_data_menu.h"

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