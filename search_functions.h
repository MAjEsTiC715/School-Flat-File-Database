int search_ClassID( int id ) {
        int result;
        struct Classes s2;
        FILE * fp = fopen( "classes.db", "r+" );
        
        while (fread(&s2,sizeof(struct Classes),1,fp) != NULL) {
                if (s2.class_id == id) {
                        printf("A record with requested id found.\n\n");
                        result = 1;
                        break;
                } 
                else {
                        result = 0;
                }
        }
        fclose (fp); 
        return result;
}

int search_AssignmentsID( int id ) {
        int result;
        struct Assignments s2;
        FILE * fp = fopen( "assignments.db", "r+" );
        
        while (fread(&s2,sizeof(struct Assignments),1,fp) != NULL) {
                if (s2.id== id) {
                        printf("A record with requested id found.\n\n");
                        result = 1;
                        break;
                } 
                else {
                        result = 0;
                }
        }
        fclose (fp); 
        return result;
}

int search_SSN( char *ssn ) {
        int result;
        struct Student s2;
        FILE * fp = fopen( "students.db", "r+" );
        
        while (fread(&s2,sizeof(struct Student),1,fp) != NULL) {
                if (strcmp (ssn, s2.ssn) == 0) {
                        printf("A record with requested ssn found.\n\n");
                        result = 1;
                        break;
                } 
                else {
                        result = 0;
                }
        }
        fclose (fp); 
        return result;
}

