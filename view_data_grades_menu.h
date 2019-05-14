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

	char tempSSN2[9];
	int tempClassID2;
	int tempAssID;
	int i;
	int result;

	switch( choice )
	{
		case 1:
			printf( "Enter Class ID (-1 for class list): " );
			scanf("%d", &tempClassID2);
			if (tempClassID2 == -1) {
				readClasses("classes.db");
				break;
			}
			result = classAverageGrade("grades.db", tempClassID2);
			printf("The class average grade is: %d \n", result);
			break;
		case 2:
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN2[9]));
			i = search_SSN(&tempSSN2[9]);
			if (i == 0) {
				printf("Student SSN not Found");
				break;
			}
			result = studentAverageGrade("grades.db", &tempSSN2[9]);
			printf("The students average grade is: %d \n", result);
			break;
		case 3:
			printf( "Enter Class ID (-1 for class list): " );
			scanf("%d", &tempClassID2);
			if (tempClassID2 == -1) {
				readClasses("classes.db");
				break;
			}
			i = search_ClassID(tempClassID2);
			if (i == 0) {
				printf("No Class Found");
				break;
			}
			printf( "Enter AssignmentID (-1 for class list): " );
			scanf("%d", &tempAssID);
			if (tempAssID == -1) {
				readAssignments("assignments.db");
				break;
			}
			i = search_AssignmentsID(tempAssID);
			if (i == 0) {
				printf("No Assignment Found");
				break;
			}

			result = assignmentAverageGrade("grades.db", tempClassID2, tempAssID);

			printf("The assignments average grade is: %d \n", result);
			break;
		case 4:
			printf( "Enter Class ID (-1 for class list): " );
			scanf("%d", &tempClassID2);
			if (tempClassID2 == -1) {
				readClasses("classes.db");
				break;
			}
			i = search_ClassID(tempClassID2);
			if (i == 0) {
				printf("No Class Found");
				break;
			}
			printf( "Enter AssignmentID (-1 for class list): " );
			scanf("%d", &tempAssID);
			if (tempAssID == -1) {
				readAssignments("assignments.db");
				break;
			}
			i = search_AssignmentsID(tempAssID);
			if (i == 0) {
				printf("No Assignment Found");
				break;
			}
			assignmentGrade("grades.db", tempClassID2, tempAssID);
			break;
		case 5:
			return;
		default:
			printf( "What???" );
			break;
	}

	view_data_grades_menu();
}