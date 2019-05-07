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

	char tempSSN2[9];
	int j;

	switch( choice )
	{
		case 1:
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN2[9]));
			j = edit_student(&student_list, &tempSSN2[9]);
			if (j == 0) {
				printf("Student SSN not Found");
				break;
			}
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