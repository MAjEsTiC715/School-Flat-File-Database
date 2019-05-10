int readStudents(char *fname) {
        FILE *fp;
        struct Student myrecord;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in students file %s:\n", fname);
        while (fread(&myrecord,sizeof(struct Student),1,fp) != NULL) {
                printf("%s\n", myrecord.first);
                printf("%s\n", myrecord.last);
                printf("%s\n\n", myrecord.ssn);
        }
        fclose(fp);
        return 0;
}

int readClasses(char *fname) {
        FILE *fp;
        struct Classes myrecord;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in classes file %s:\n", fname);
        while (fread(&myrecord,sizeof(struct Classes),1,fp) != NULL) {
                printf("%d\n", myrecord.class_id);
                printf("%s\n", myrecord.class_title);
        }
        fclose(fp);
        return 0;
}

int readAssignments(char *fname) {
        FILE *fp;
        struct Assignments myrecord;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in assignments file %s:\n", fname);
        while (fread(&myrecord,sizeof(struct Assignments),1,fp) != NULL) {
                printf("%d\n", myrecord.assignment_class_id);
                printf("%d\n", myrecord.id);
                printf("%s\n", myrecord.assignment_title);
                printf("%d\n", myrecord.point_value);
        }
        fclose(fp);
        return 0;
}

int readGrades(char *fname) {
        FILE *fp;
        struct Grade myrecord;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in grades file %s:\n", fname);
        while (fread(&myrecord,sizeof(struct Grade),1,fp) != NULL) {
                printf("class id: %d\n", myrecord.class_id_g);
                printf("assignments id: %d\n", myrecord.assignment_id);
                printf("student ssn: %s\n", myrecord.student_ssn);
                printf("points: %d\n", myrecord.points);
        }
        fclose(fp);
        return 0;
}

int readEnrollments(char *fname) {
        FILE *fp;
        struct Enrollment myrecord;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in enrollments file %s:\n", fname);
        while (fread(&myrecord,sizeof(struct Enrollment),1,fp) != NULL) {
                printf("%d\n", myrecord.enrollment_class_id);
                printf("%s\n", myrecord.student_ssn);
        }
        fclose(fp);
        return 0;
}