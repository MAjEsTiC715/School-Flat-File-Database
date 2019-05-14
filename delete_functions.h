int deleteStudent(char *fname, char *ssn) {
        FILE *fp;
        FILE *fp_tmp;
        int found=0;
        struct Student myrecord;

        fp=fopen(fname, "rb");
        if (!fp) {
                printf("Unable to open file %s", fname);
                return -1;
        }
        fp_tmp=fopen("tmp.bin", "wb");
        if (!fp_tmp) {
                printf("Unable to open file temp file.");
                return -1;
        }
        
        while (fread(&myrecord,sizeof(struct Student),1,fp) != '\0') {
                if (strcmp (ssn, myrecord.ssn) == 0) {
                        printf("A record with requested name found and deleted.\n\n");
                        found=1;
                } else {
                        fwrite(&myrecord, sizeof(struct Student), 1, fp_tmp);
                }
        }
        if (! found) {
                printf("No record(s) found with the requested name: %s\n\n", ssn);
        }

        fclose(fp);
        fclose(fp_tmp);

        remove(fname);
        rename("tmp.bin", fname);

        return 0;
}

int deleteClass(char *fname, int id) {
        FILE *fp;
        FILE *fp_tmp;
        int found=0;
        struct Classes myrecord;

        fp=fopen(fname, "rb");
        if (!fp) {
                printf("Unable to open file %s", fname);
                return -1;
        }
        fp_tmp=fopen("tmp.bin", "wb");
        if (!fp_tmp) {
                printf("Unable to open file temp file.");
                return -1;
        }
        
        while (fread(&myrecord,sizeof(struct Classes),1,fp) != '\0') {
                if (myrecord.class_id ==  id) {
                        printf("A record with requested name found and deleted.\n\n");
                        found=1;
                } else {
                        fwrite(&myrecord, sizeof(struct Classes), 1, fp_tmp);
                }
        }
        if (! found) {
                printf("No record(s) found with the requested name: %d\n\n", id);
        }

        fclose(fp);
        fclose(fp_tmp);

        remove(fname);
        rename("tmp.bin", fname);

        return 0;
}

int deleteAssignment(char *fname, int id, int ass_id) {
        FILE *fp;
        FILE *fp_tmp;
        int found=0;
        struct Assignments myrecord;

        fp=fopen(fname, "rb");
        if (!fp) {
                printf("Unable to open file %s", fname);
                return -1;
        }
        fp_tmp=fopen("tmp.bin", "wb");
        if (!fp_tmp) {
                printf("Unable to open file temp file.");
                return -1;
        }
        
        while (fread(&myrecord,sizeof(struct Assignments),1,fp) != '\0') {
                if (myrecord.assignment_class_id == id && myrecord.id == ass_id) {
                        printf("A record with requested name found and deleted.\n\n");
                        found=1;
                } else {
                        fwrite(&myrecord, sizeof(struct Assignments), 1, fp_tmp);
                }
        }
        if (! found) {
                printf("No record(s) found with the requested name: %d\n\n", id);
        }

        fclose(fp);
        fclose(fp_tmp);

        remove(fname);
        rename("tmp.bin", fname);

        return 0;
}

int deleteGrade(char *fname, int id, int ass_id, char *ssn) {
        FILE *fp;
        FILE *fp_tmp;
        int found=0;
        struct Grade myrecord;

        fp=fopen(fname, "rb");
        if (!fp) {
                printf("Unable to open file %s", fname);
                return -1;
        }
        fp_tmp=fopen("tmp.bin", "wb");
        if (!fp_tmp) {
                printf("Unable to open file temp file.");
                return -1;
        }
        
        while (fread(&myrecord,sizeof(struct Grade),1,fp) != '\0') {
                if (myrecord.class_id_g == id && myrecord.assignment_id == ass_id && (strcmp (ssn, myrecord.student_ssn) == 0)) {
                        printf("A record with requested name found and deleted.\n\n");
                        found=1;
                } else {
                        fwrite(&myrecord, sizeof(struct Grade), 1, fp_tmp);
                }
        }
        if (! found) {
                printf("No record(s) found with the requested name: %d\n\n", id);
        }

        fclose(fp);
        fclose(fp_tmp);

        remove(fname);
        rename("tmp.bin", fname);

        return 0;
}

int deleteEnrollment(char *fname, int id, char *ssn) {
        FILE *fp;
        FILE *fp_tmp;
        int found=0;
        struct Enrollment myrecord;

        fp=fopen(fname, "rb");
        if (!fp) {
                printf("Unable to open file %s", fname);
                return -1;
        }
        fp_tmp=fopen("tmp.bin", "wb");
        if (!fp_tmp) {
                printf("Unable to open file temp file.");
                return -1;
        }
        
        while (fread(&myrecord,sizeof(struct Enrollment),1,fp) != '\0') {
                if (myrecord.enrollment_class_id == id && (strcmp (ssn, myrecord.student_ssn) == 0)) {
                        printf("A record with requested name found and deleted.\n\n");
                        found=1;
                } else {
                        fwrite(&myrecord, sizeof(struct Enrollment), 1, fp_tmp);
                }
        }
        if (! found) {
                printf("No record(s) found with the requested name: %d\n\n", id);
        }

        fclose(fp);
        fclose(fp_tmp);

        remove(fname);
        rename("tmp.bin", fname);

        return 0;
}