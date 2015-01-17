int reduce_for_int(int *, int, int, int (*)(int, int));
float reduce_for_float(float *, int, float, float (*)(float, float));
char reduce_for_char(char *, int, char, char (*)(char, char));
char* reduce_for_string(char **, int, char*, char* (*)(char*, char*));
