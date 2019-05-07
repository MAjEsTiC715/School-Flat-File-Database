struct Student {
        char first[30];
        char last[30];
        char ssn[9];
};

struct Classes {
	int class_id;
	char class_title[30];
};

struct Enrollment {
        int enrollment_class_id;
        char student_ssn[9];
};

struct Assignments {
        int id;
        char assignment_title[30];
        int point_value;
        int assignment_class_id;
};

struct Grade {
        int assignment_id;
        char student_ssn[9];
        int points;
};

struct node {
        struct Student *s;
        struct Classes *c;
        struct Enrollment *e;
        struct Assignments *a;
        struct Grade *g;
        struct node *next;
        struct node *prev;
};

struct dll student_list;
struct dll class_list;
struct dll enrollment_list;
struct dll assignments_list;
struct dll grade_list;

struct dll {
        struct node *head;
        struct node *tail;
        int length;
};

float avg_age( struct dll *list ) {
        float total_age = 0;
        float num_ages = 0;

        struct node *n = list->head;

        while( n != NULL ) {
                total_age += n->c->class_id;
                num_ages++;
                n = n->next;
        }

        return total_age / num_ages;
}

float avg_name_length( struct dll *list ) {
        int i = 0;
        float total_chars = 0;
        float num_names = 0;

        struct node *n = list->head;

        while( n != NULL ) {
                i = 0;
                while( *( n->c->class_title + i ) != '\0' ) {
                        total_chars++;
                        i++;
                }

                num_names++;
                n = n->next;
        }

        return total_chars / num_names;
}

void add_student_node( struct dll *list, char *newfirst, char *newlast, char *newssn ) {
        struct node *n = malloc( sizeof( struct node ) );

        struct Student *s = malloc( sizeof( struct Student ) );

        strcpy(s->first, newfirst);
        strcpy(s->last, newlast);
        strcpy(s->ssn, newssn);

        n->s = s;
        n->next = NULL;

        if ( list->length == 0 ) {
                n->prev = NULL;
                list->head = n;
                list->tail = n;
        }
        else {
                n->prev = list->tail;
                list->tail->next = n;
                list->tail = n;
        }

        list->length++;
}

void add_class_node( struct dll *list, int newid, char *newname ) {
        struct node *n = malloc( sizeof( struct node ) );

        struct Classes *c = malloc( sizeof( struct Classes ) );

        c->class_id = newid;
        strcpy(c->class_title, newname);

        n->c = c;
        n->next = NULL;

        if ( list->length == 0 ) {
                n->prev = NULL;
                list->head = n;
                list->tail = n;
        }
        else {
                n->prev = list->tail;
                list->tail->next = n;
                list->tail = n;
        }

        list->length++;
}

void add_enrollment_node( struct dll *list, int newid, char *newssn ) {
        struct node *n = malloc( sizeof( struct node ) );

        struct Enrollment *e = malloc( sizeof( struct Enrollment ) );

        e->enrollment_class_id = newid;
        strcpy(e->student_ssn, newssn);

        n->e = e;
        n->next = NULL;

        if ( list->length == 0 ) {
                n->prev = NULL;
                list->head = n;
                list->tail = n;
        }
        else {
                n->prev = list->tail;
                list->tail->next = n;
                list->tail = n;
        }

        list->length++;
}

void add_assignments_node( struct dll *list, int newid, char *newtitle, int newpointvalue, int newclassid ) {
        struct node *n = malloc( sizeof( struct node ) );

        struct Assignments *a = malloc( sizeof( struct Assignments ) );

        a->id = newid;
        strcpy(a->assignment_title, newtitle);
        a->point_value = newpointvalue;
        a->assignment_class_id = newclassid;

        n->a = a;
        n->next = NULL;

        if ( list->length == 0 ) {
                n->prev = NULL;
                list->head = n;
                list->tail = n;
        }
        else {
                n->prev = list->tail;
                list->tail->next = n;
                list->tail = n;
        }

        list->length++;
}

void add_grade_node( struct dll *list, int newid, char *newssn, int newpoints ) {
        struct node *n = malloc( sizeof( struct node ) );

        struct Grade *g = malloc( sizeof( struct Grade ) );

        g->assignment_id = newid;
        strcpy(g->student_ssn, newssn);
        g->points = newpoints;

        n->g = g;
        n->next = NULL;

        if ( list->length == 0 ) {
                n->prev = NULL;
                list->head = n;
                list->tail = n;
        }
        else {
                n->prev = list->tail;
                list->tail->next = n;
                list->tail = n;
        }

        list->length++;
}

void func2( struct node *n, int value ) {
        if (value == 1) {
                printf( "\n %s, %s, %s", n->s->first, n->s->last, n->s->ssn );
        }
        if (value == 2) {
                printf( "\n %d, %s", n->c->class_id, n->c->class_title );
        }
        if (value == 3) {
                printf( "\n %d, %s", n->e->enrollment_class_id, n->e->student_ssn );
        }
        if (value == 4) {
                printf( "\n %d, %s, %d, %d", n->a->id, n->a->assignment_title, n->a->point_value, n->a->assignment_class_id );
        }
        if (value == 5) {
                printf( "\n %d, %s, %d", n->g->assignment_id, n->g->student_ssn, n->g->points );
        }

        if ( n->next != NULL )
                printf( ", " );
        else
                printf( "\n" );
}

void print_nodes( struct dll *list, int value ) {
        struct node *n = list->head;

        while( n != NULL ) {
                func2( n, value );
                n = n->next;
        }
}

int search_classfunc( struct node *n, int id ) {
        if ( n->next != NULL ) 
                if (n->c->class_id == id) {
                        return 1;
                }
        
        return 0;
}

int search_ClassID( struct dll *list, int id ) {
        int result;
        struct node *n = list->head;

        while( n != NULL ) {
                result = search_classfunc( n, id );
                if (result == 1) {
                        return result;
                }
                else {
                        n = n->next;
                }
        }
        return result;
}