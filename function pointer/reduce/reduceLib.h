int reduce_for_int(int *, int, int, int (*)(int, int));
float reduce_for_float(float *, int, float, float (*)(float, float));
// float reduceFloat (float *array, int array_length, float (*function_ptr)(float,float,int, float *), float initialValue);