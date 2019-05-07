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