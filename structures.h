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