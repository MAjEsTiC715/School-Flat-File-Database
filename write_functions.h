void write_students(char *first, char *last, char *ssn) {
        FILE *outfile;
        struct Student *s = malloc( sizeof( struct Student ) );

        strcpy(s->first, first);
        strcpy(s->last, last);
        strcpy(s->ssn, ssn);

        outfile = fopen ("students.db", "a+");

        if (outfile != NULL){
                fwrite (s, sizeof(struct Student), 1, outfile);
        }

        fclose (outfile); 
}
void write_classes(char *title, int id) {
        FILE *outfile;
        struct Classes *c = malloc( sizeof( struct Classes ) );

        c->class_id = id;
        strcpy(c->class_title, title);

        outfile = fopen ("classes.db", "a+");

        if (outfile != NULL){
                fwrite (c, sizeof(struct Classes), 1, outfile);
        }

        fclose (outfile); 
}
void write_assignments(int class_id, int id, char *title, int points) {
        FILE *outfile;
        struct Assignments *a = malloc( sizeof( struct Assignments ) );

        a->assignment_class_id = class_id;
        a->id = id;
        strcpy(a->assignment_title, title);
        a->point_value = points;

        outfile = fopen ("assignments.db", "a+");

        if (outfile != NULL){
                fwrite (a, sizeof(struct Assignments), 1, outfile);
        }

        fclose (outfile); 
}
void write_enrollments(int id, char *ssn) {
        FILE *outfile;
        struct Enrollment *e = malloc( sizeof( struct Enrollment ) );

        e->enrollment_class_id = id;
        strcpy(e->student_ssn, ssn);

        outfile = fopen ("enrollment.db", "a+");

        if (outfile != NULL){
                fwrite (e, sizeof(struct Enrollment), 1, outfile);
        }

        fclose (outfile); 
}
void write_grades(int class_id, int id, char *ssn, int points) {
        FILE *outfile;
        struct Grade *g = malloc( sizeof( struct Grade ) );

        g->class_id_g = class_id;
        g->assignment_id = id;
        strcpy(g->student_ssn, ssn);
        g->points = points;

        outfile = fopen ("grades.db", "a+");

        if (outfile != NULL){
                fwrite (g, sizeof(struct Grade), 1, outfile);
        }

        fclose (outfile); 
}