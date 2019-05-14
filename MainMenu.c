#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "search_functions.h"
#include "edit_functions.h"
#include "write_functions.h"
#include "delete_functions.h"
#include "read_functions.h"
#include "view_grade_functions.h"
#include "add_menu.h"
#include "edit_menu.h"
#include "delete_menu.h"
#include "view_data_grades_menu.h"
#include "view_data_menu.h"

int handle_env( int wordc, char **words ) {
	int CLASSID = 1;
	int ASSID = 1;
	int i;
	
	if ( wordc == 1 ) {
		if ( !strcmp( words[0], "exit" ) || !strcmp( words[0], "quit" ) )
			return -1;
	}
	else if ( wordc == 2 && !strcmp( words[0], "use" ) && !strcmp( words[1], "menus" ) ) {
		return 0;
	}
	else if ( wordc == 2 && !strcmp( words[0], "view" ) && !strcmp( words[1], "students" ) ) {
		readStudents("students.db");
		return 1;
	}
	else if ( wordc == 2 && !strcmp( words[0], "view" ) && !strcmp( words[1], "classes" ) ) {
		readClasses("classes.db");
		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "view" ) && !strcmp( words[1], "assignments" ) ) {
		readAssignments("assignments.db");
		return 1;
	}
	else if ( wordc == 4 && !strcmp( words[0], "view" ) && !strcmp( words[1], "grades" ) ) {
		struct Grade *g = malloc( sizeof( struct Grade ) );

        g->class_id_g = words[2];
        g->assignment_id = words[3];
        assignmentGrade("grades.db", g->class_id_g, g->assignment_id);
		return 1;
	}
	else if ( wordc == 5 && !strcmp( words[0], "view" ) && !strcmp( words[1], "average" && !strcmp( words[2], "grades") )) {
		struct Grade *g = malloc( sizeof( struct Grade ) );

        g->class_id_g = words[3];
        g->assignment_id = words[4];
        assignmentAverageGrade("grades.db", g->class_id_g, g->assignment_id);
		return 1;
	}
	else if ( wordc == 2 && !strcmp( words[0], "view" ) && !strcmp( words[1], "students" ) ) {
		readStudents("students.db");
		return 1;
	}
	else if ( wordc == 2 && !strcmp( words[0], "view" ) && !strcmp( words[1], "students" ) ) {
		readStudents("students.db");
		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "add" ) && !strcmp( words[1], "class" ) ) {
		struct Classes *c = malloc( sizeof( struct Classes ) );

        memcpy(c->class_title, words[2], 30);
        write_classes(c->class_title, ClassID);
        CLASSID +=1;
		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "edit" ) && !strcmp( words[1], "class" ) ) {
		struct Classes *c = malloc( sizeof( struct Classes ) );

        memcpy(c->class_title, words[2], 30);
        edit_class(c->class_title, ClassID);
		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "delete" ) && !strcmp( words[1], "student" ) ) {
		struct Student *s = malloc( sizeof( struct Student ) );
		memcpy( s->ssn, words[2], 9 );
		deleteStudent("students.db", s->ssn);
		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "delete" ) && !strcmp( words[1], "class" ) ) {
		struct Classes *c = malloc( sizeof( struct Classes ) );

        c->class_id = words[2];
		deleteStudent("classes.db", c->class_id);
		return 1;
	}
	else if ( wordc == 4 && !strcmp( words[0], "delete" ) && !strcmp( words[1], "assignment" ) ) {
		struct Assignments *a = malloc( sizeof( struct Assignments ) );

        a->assignment_class_id = words[2];
        a->id = words[3];
		deleteAssignment("assignments.db", a->assignment_class_id, a->id);
		return 1;
	}
	else if ( wordc == 5 && !strcmp( words[0], "delete" ) && !strcmp( words[1], "grade" ) ) {
		struct Grade *g = malloc( sizeof( struct Grade ) );

        g->class_id_g = words[2];
        g->assignment_id = words[3];
        memcpy(g->student_ssn, words[4], 9);
		deleteGrade("grades.db", g->class_id_g, g->assignment_id, g->student_ssn);
		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "drop" ) ) {
		struct Enrollment *e = malloc( sizeof( struct Enrollment ) );

        e->enrollment_class_id = words[1];
        memcpy(e->student_ssn, words[2], 9);

        deleteEnrollment("enrollment.db", e->enrollment_class_id, e->student_ssn);

		return 1;
	}
	else if ( wordc == 3 && !strcmp( words[0], "enroll" ) ) {
		struct Enrollment *e = malloc( sizeof( struct Enrollment ) );

        e->enrollment_class_id = words[1];
        memcpy(e->student_ssn, words[2], 9);

        write_enrollments(e->enrollment_class_id, e->student_ssn);

		return 1;
	}
	else if ( wordc == 5 && !strcmp( words[0], "add" ) && !strcmp( words[1], "student" ) ) {
		struct Student *s = malloc( sizeof( struct Student ) );
		memcpy( s->first, words[2], 30 );
		memcpy( s->last, words[3], 30 );
		memcpy( s->ssn, words[4], 9 );
		write_students(s->first, s->last, s->ssn);
		return 1;
	}
	else if ( wordc == 5 && !strcmp( words[0], "edit" ) && !strcmp( words[1], "student" ) ) {
		struct Student *s = malloc( sizeof( struct Student ) );
		memcpy( s->first, words[2], 30 );
		memcpy( s->last, words[3], 30 );
		memcpy( s->ssn, words[4], 9 );
		edit_student(s->first, s->last, s->ssn);
		return 1;
	}
	else if ( wordc == 5 && !strcmp( words[0], "add" ) && !strcmp( words[1], "assignment" ) ) {
		struct Assignments *a = malloc( sizeof( struct Assignments ) );

        a->assignment_class_id = words[2];
        a->id = ASSID;
        memcpy(a->assignment_title, words[3], 30);
        a->point_value = words[4];
		write_assignments(a->assignment_class_id, a->id, a->assignment_title, a->point_value);
		return 1;
	}
	else if ( wordc == 5 && !strcmp( words[0], "edit" ) && !strcmp( words[1], "assignment" ) ) {
		struct Assignments *a = malloc( sizeof( struct Assignments ) );

        a->assignment_class_id = words[2];
        a->id = ASSID;
        memcpy(a->assignment_title, words[3], 30);
        a->point_value = words[4];
		edit_assignment(a->assignment_class_id, a->id, a->assignment_title, a->point_value);
		return 1;
	}
	else if ( wordc == 6 && !strcmp( words[0], "add" ) && !strcmp( words[1], "grade" ) ) {
		struct Grade *g = malloc( sizeof( struct Grade ) );

        g->class_id_g = words[2];
        g->assignment_id = words[3];
        memcpy(g->student_ssn, words[4], 9);
        g->points = words[5];
		write_grades(g->class_id_g, g->assignment_id, g->student_ssn, g->points);
		return 1;
	}
	else if ( wordc == 6 && !strcmp( words[0], "edit" ) && !strcmp( words[1], "grade" ) ) {
		struct Grade *g = malloc( sizeof( struct Grade ) );

        g->class_id_g = words[2];
        g->assignment_id = words[3];
        memcpy(g->student_ssn, words[4], 9);
        g->points = words[5];
		edit_grade(g->class_id_g, g->assignment_id, g->student_ssn, g->points);
		return 1;
	}
	
	return 1;			
}

int env() {
	char c;
	char *line;
	char *word;
	char **words;
	
	int returnval = 1;
	int i;
	int j;
	int inc = 200;
	int length = inc;
	int index = 0;
	
	int current_word = 0;
	int word_count = 1;
	int word_length;
	int last_space = 0;
	
	while ( 1 ) {
		length = inc;
		index = 0;
		current_word = 0;
		word_count = 1;
		last_space = 0;
		
		line = malloc( length );
		
		printf( "Environment\n" );
		
		/*
		 * XXXXX
		 * 012345
		 * XXXXXXXXXX
		 * 012345
		 */
		
		while( ( c = getchar() ) != '\n' ) {
			if ( index >= length ) {
				length += inc;
				line = realloc( line, length );
			}
			
			if ( c == ' ' )
				word_count++;
			
			line[index] = c;
			index++;
		}
		
		line[index] = '\0';
		
		words = malloc( ( word_count ) * sizeof( char * ) );
		
		/* words is a pointer to a char pointer
		 * word_count = number of spaces + 1
		 */
		
		for( i = 0; i < index; i++ ) {
			if ( line[i] == ' ' ) {
				word_length = i - last_space + 1;
				word = malloc( word_length );
				memcpy( word, &line[0] + last_space, word_length - 1 );
				word[word_length - 1] = '\0';
				words[current_word] = word;
				last_space = i + 1;
				current_word++;
			}
		}
		
		word_length = index - last_space + 1;
		word = malloc( word_length );
		memcpy( word, &line[0] + last_space, word_length - 1 );
		words[current_word] = word;
		
		returnval = handle_env( word_count, words );
		
		for( i = word_count - 1; i >= 0; i-- ) {
			free( words[i] );
		}
		
		free( words );
		free( line );
		
		if ( returnval == -1 || returnval == 0 )
			break;
	}
	 
	return returnval; 
}

void handle_cli( int argc, char **argv ) {
	int i;
	int start = 2;
	struct Student *s = malloc( sizeof( struct Student * ) );
	
	if ( !strcmp( argv[1], "-add-student" ) ) {
		for( i = 0; i < 3; i++ ) {
			if ( !strcmp( argv[start + 2 * i], "-f" ) )
				memcpy( s->first, argv[start + 2*i + 1], 30 );
			else if ( !strcmp( argv[start + 2 * i], "-l" ) )
				memcpy( s->last, argv[start + 2*i + 1], 30 );
			else if ( !strcmp( argv[start + 2 * i], "-s" ) )
				memcpy( s->ssn, argv[start + 2*i + 1], 9 );
		}
		
		//add_student( s );
	}
}

int menu( int choice ) {
	switch( choice ) {
		case 0:
			printf( "This is the main menu\n" );
			choice = main_menu();
			break;
		case 1:
			printf( "This is the add menu\n" );
			break;
		case 2:
			printf( "This is the edit menu\n" );
			break;
		case 3:
			printf( "this is the delete menu\n" );
			break;
		case 4:
			printf( "This is the view menu\n" );
			break;
	}
	
	return choice;
		
}


int main2( int argc, char **argv ) {
	int menuopt = 0;
	
	if ( argc > 1 ) {
		handle_cli( argc, argv );
		return 1;
	}
	
	while ( menuopt != -1 ) {
		menuopt = menu( menuopt );
	}
	
	return 1;
}

void main_menu()
{
	int choice;
	printf( "Main Menu\n" );
	printf( "1. Add Data\n" );
	printf( "2. Edit Data\n" );
	printf( "3. Delete Data\n" );
	printf( "4. View Data\n" );
	printf( "5. Use Command Line Environment\n" );
	printf( "6. Exit\n" );
	printf( "Please enter 1-6: " );

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
		case 5:
			env();
			return;
		case 6: //Exiting
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