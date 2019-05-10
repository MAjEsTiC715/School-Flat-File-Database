void delete_menu()
{
	int choice;
	printf( "Delete Menu\n" );
	printf( "1. Delete Student\n" );
	printf( "2. Delete Class\n" );
	printf( "3. Delete Assignment\n" );
	printf( "4. Delete Grade\n" );
	printf( "5. Drop Student\n");
	printf( "6. Return to Main Menu\n" );

	printf( "Please enter 1-6: " );

	scanf( "%d", &choice );

	clear_buffer();

	char tempSSN2[9];
	int tempClassID2;
	int tempAssID;
	int i;

	switch( choice )
	{
		case 1:
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN2[9]));
			i = search_SSN(&tempSSN2[9]);
			if (i == 0) {
				printf("Student SSN not Found");
				break;
			}

			deleteStudent("students.db", &tempSSN2[9]);
			break;
		case 2:
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

			deleteClass("classes.db", tempClassID2);
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

			deleteAssignment("assignments.db", tempClassID2, tempAssID);
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
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN2[9]));
			i = search_SSN(&tempSSN2[9]);
			if (i == 0) {
				printf("Student SSN not Found");
				break;
			}

			deleteGrade("grades.db", tempClassID2, tempAssID, &tempSSN2[9]);
			break;
		case 5:
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
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN2[9]));
			i = search_SSN(&tempSSN2[9]);
			if (i == 0) {
				printf("Student SSN not Found");
				break;
			}

			deleteEnrollment("enrollment.db", tempClassID2, &tempSSN2[9]);
			break;
		case 6:
			return;
		default:
			printf( "What???" );
			break;
	}

	delete_menu();
}