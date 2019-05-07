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