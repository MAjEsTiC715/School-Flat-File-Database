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
        int assignment_class_id;
        int id;
        char assignment_title[30];
        int point_value;
};

struct Grade {
        int class_id_g;
        int assignment_id;
        char student_ssn[9];
        int points;
};



int classAverageGrade(char *fname, int class_id) {
        FILE *fp;
        int total;
        int num;
        struct Grade myrecord;

        fp=fopen(fname,"r");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("Calculating average class grades %s:\n", fname);
        while (fread(&myrecord,sizeof(struct Grade),1,fp) != NULL) {
                if (myrecord.class_id_g == class_id){
                        fscanf(fp, "%d", &total);
                        printf("%d\n", total);
                        num += 1;
                }
        }
        fclose(fp);
        printf("%d\n", num);
        return (total / num);
}