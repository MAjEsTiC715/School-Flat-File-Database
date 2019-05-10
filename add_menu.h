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
	int  tempClassID2;
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

			write_students(&tempF[30], &tempL[30], &tempS[9]);

			break;
		case 2:
			printf( "Enter Class Name: " );
			scanf("%s", &(temp[30]));
			write_classes(&temp[30], ClassID);
			ClassID += 1;

			break;
		case 3:
			printf( "Enter Class ID (-1 for class list): " );
			scanf("%d", &tempClassID);
			if (tempClassID == -1) {
				readClasses("classes.db");
				break;
			}
			i = search_ClassID(tempClassID);
			if (i == 0) {
				printf("No Class Found");
				break;
			}
			printf( "Enter Assignment Name: " );
			scanf("%s", &(tempAssName[30]));
			printf( "Enter Point Value: " );
			scanf("%d", &tempPoints);
			write_assignments(tempClassID, AssignmentID, &tempAssName[30], tempPoints);
			AssignmentID += 1;

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
			scanf("%s", &(tempSSN[9]));
			i = search_SSN(&tempSSN[9]);
			if (i == 0) {
				printf("Student SSN not Found");
				break;
			}
			printf( "Enter Points: " );
			scanf("%d", &tempPoints);

			write_grades(tempClassID2, tempAssID, &tempSSN[9], tempPoints);
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
			scanf("%s", &(tempSSN[9]));
			i = search_SSN(&tempSSN[9]);
			if (i == 0) {
				printf("Student SSN not Found\n");
				break;
			}

			write_enrollments(tempClassID2, &tempSSN[9]);
			break;
		case 6:
			return;
		default:
			printf( "What???" );
			break;
		}

	add_menu();
}