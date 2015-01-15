int filter(int *, int, int **, int (*)(int, int, int *));
int filter_for_float(float *, int, float **, int (*)(float, int, float *));
int filter_for_char(char *, int, char **, int (*)(char, int, char *));
int filter_for_string(char **, int, char **, int (*)(char, int, char *));
