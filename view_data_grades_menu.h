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

	readGrades("grades.db");

	int tempClassID2;

	switch( choice )
	{
		case 1:
			printf( "Enter Class ID (-1 for class list): " );
			scanf("%d", &tempClassID2);
			if (tempClassID2 == -1) {
				readClasses("classes.db");
				break;
			}
			printf("The class average grade is: %d \n", classAverageGrade("classes.db", tempClassID2));
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
			return;
		default:
			printf( "What???" );
			break;
	}

	view_data_grades_menu();
}