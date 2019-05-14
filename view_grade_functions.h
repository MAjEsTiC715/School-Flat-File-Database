int classAverageGrade(char *fname, int class_id) {
        FILE *fp;
        int total;
        int num;
        int result;
        struct Grade g;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in grades file %s:\n", fname);
        while (fread(&g,sizeof(struct Grade),1,fp) != '\0') {
                if (g.class_id_g == class_id) {
                        total += g.points;
                        num += 1;
                }
        }
        fclose(fp);
        result = total / num;
        return result;
}

int studentAverageGrade(char *fname, char *ssn) {
        FILE *fp;
        int total;
        int num;
        int result;
        struct Grade g;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in grades file %s:\n", fname);
        while (fread(&g,sizeof(struct Grade),1,fp) != '\0') {
                if (strcmp (ssn, g.student_ssn) == 0) {
                        total += g.points;
                        num += 1;
                }
        }
        fclose(fp);
        result = total / num;
        return result;
}

int assignmentAverageGrade(char *fname, int class_id, int id) {
        FILE *fp;
        int total;
        int num;
        int result;
        struct Grade g;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in grades file %s:\n", fname);
        while (fread(&g,sizeof(struct Grade),1,fp) != '\0') {
                if (g.class_id_g == class_id && g.assignment_id == id) {
                        total += g.points;
                        num += 1;
                }
        }
        fclose(fp);
        result = total / num;
        return result;
}

int assignmentGrade(char *fname, int class_id, int id) {
        FILE *fp;
        struct Grade g;

        fp=fopen(fname,"r+");
        if (!fp) {
                printf("Unable to open file!");
                return -1;
        }

        printf("The following records are in grades file %s:\n", fname);
        while (fread(&g,sizeof(struct Grade),1,fp) != '\0') {
                if (g.class_id_g == class_id && g.assignment_id == id) {
                        printf("%d\n", g.points);
                }
        }
        fclose(fp);
        return 0;
}