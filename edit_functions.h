void edit_student( char *first, char *last, char *ssn ) {
        int j = 0;
        
        struct Student *s = malloc( sizeof( struct Student ) );
        struct Student s2;
        strcpy( s->first, first);
        strcpy( s->last, last);
        strcpy( s->ssn, ssn);
        
        FILE * fp = fopen( "students.db", "r+" );
        
        while (fread(&s2,sizeof(struct Student),1,fp) != '\0') {
                if ( strcmp( s->ssn, s2.ssn) == 0 ){
                        printf("%d\n", j);
                        break;
                }
                else {
                        j += 1;
                }
        }
        
        fseek( fp, j * sizeof( struct Student ), SEEK_SET );
        fwrite( s, sizeof( struct Student ), 1, fp );   
        fclose (fp); 
} 
void edit_class( char *title, int id ) {
        int i = id-1;
        
        struct Classes *c = malloc( sizeof( struct Classes ) );
        c->class_id = id;
        strcpy( c->class_title, title);
        
        FILE * fp = fopen( "classes.db", "r+" );
        
        fseek( fp, i * sizeof( struct Classes ), SEEK_SET );
        fwrite( c, sizeof( struct Classes ), 1, fp );
        fclose (fp); 
}  

void edit_assignment( int class_id, int id, char *title, int points ) {
        int i = 0;
        
        struct Assignments *a = malloc( sizeof( struct Assignments ) );
        struct Assignments a2;
        a->assignment_class_id = class_id;
        a->id = id;
        strcpy(a->assignment_title, title);
        a->point_value = points;
        
        FILE * fp = fopen( "assignments.db", "r+" );
        
        while (fread(&a2,sizeof(struct Assignments),1,fp) != '\0') {
                if (a2.assignment_class_id == class_id && a2.id == id) {
                        printf("A record with requested name found.\n\n");
                        break;
                } 
                else {
                        i += 1;
                }
        }
        
        fseek( fp, i * sizeof( struct Assignments ), SEEK_SET );
        fwrite( a, sizeof( struct Assignments ), 1, fp );
        fclose (fp); 
}   

void edit_grade( int class_id, int id, char *ssn, int points ) {
        int i = 0;
        
        struct Grade *g = malloc( sizeof( struct Grade ) );
        struct Grade g2;
        g->class_id_g = class_id;
        g->assignment_id = id;
        strcpy( g->student_ssn, ssn);
        g->points = points;
        
        FILE * fp = fopen( "grades.db", "r+" );
        
        while (fread(&g2,sizeof(struct Grade),1,fp) != '\0') {
                if (g2.class_id_g == class_id && g2.assignment_id == id && (strcmp (ssn, g2.student_ssn) == 0)) {
                        printf("A record with requested name found.\n\n");
                        break;
                } 
                else {
                        i += 1;
                }
        }
        
        fseek( fp, i * sizeof( struct Grade ), SEEK_SET );
        fwrite( g, sizeof( struct Grade ), 1, fp );

        fclose (fp);
}   