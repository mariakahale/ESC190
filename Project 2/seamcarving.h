#if !defined(SEAMCARVING_H)
#define SEAMCARVING_H
#include "c_img.h"
// #include <math.h>

double min_of_2(uint8_t a, uint8_t b);
double min_of_3(int a, int b, int c);
void calc_energy(struct rgb_img *im, struct rgb_img **grad);
void dynamic_seam(struct rgb_img *grad, double **best_arr);
void print_dynamic_table(struct rgb_img *grad, double **best_arr);
void recover_path(double *best, int height, int width, int **path);
void print_path(int **path, struct rgb_img *grad);
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path);

#endif