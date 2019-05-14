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

	char tempF[30];
	char tempL[30];
	char tempClass[30];
	char tempSSN2[9];
	char tempASS[30];
	int tempPoint;
	int tempClassID2;
	int tempAssID;
	int i;
	int j;

	switch( choice )
	{
		case 1:
			printf( "Enter Student SSN: " );
			scanf("%s", &(tempSSN2[9]));
			j = search_SSN(&tempSSN2[9]);
			if (j == 0) {
				printf("Student SSN not Found");
				break;
			}
			else {
				printf("Enter New First Name (leave blank to not change): ");
        		scanf("%s", &(tempF[30]));
        		printf("Enter New Last Name (leave blank to not change): ");
        		scanf("%s", &(tempL[30]));
        		edit_student(&tempF[30], &tempL[30], &tempSSN2[9]);
			}
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
			else {
				printf( "Enter New Class Title (leave blank to not change): " );
				scanf(" %s", &(tempClass[30]));

				edit_class(&tempClass[30], tempClassID2);
			}
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
			printf( "Enter New Assignment Title (leave blank to not change): " );
			scanf("%s", &(tempASS[30]));
			printf( "Enter New Point Value (leave blank to not change): " );
			scanf("%d", &tempPoint);

			edit_assignment(tempClassID2, tempAssID, &tempASS[30], tempPoint);
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
			printf( "Enter Points: " );
			scanf("%d", &tempPoint);
			
			edit_grade(tempClassID2, tempAssID, &tempSSN2[9], tempPoint);
			break;
		case 5:
			return;
		default:
			printf( "What???" );
			break;
	}

	edit_menu();
}