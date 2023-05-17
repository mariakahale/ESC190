#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "seamcarving.h"
// #include "c_img.h"
#include "c_img.c"

double min_of_2(uint8_t a, uint8_t b){
    if (a<b){
        return (double) a;
    }
    else if (a>b){
        return (double) b;
    }
    return (double) a;
}
double min_of_3(int a, int b, int c){
    if(a<b && a<c){
        return (double) a;
}
    else if(b<c){
        return (double) b;
    }
    else{
        return (double) c;
    }
}
void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    create_img(grad, im->height,im->width);
    int delta_x,delta_y;
    uint8_t energy;
    for (int y = 0; y < (im->height); y++){
        for (int x = 0; x < (im->width); x++){
            int R_x,G_x,B_x,R_y,G_y,B_y;
            //within bounds
            if (x < (im->width)-1 && x!=0){
              R_x = get_pixel(im, y,x+1,0) - get_pixel(im, y,x-1,0);
              G_x = get_pixel(im, y,x+1,1) - get_pixel(im, y,x-1,1);
              B_x = get_pixel(im, y,x+1,2) - get_pixel(im, y,x-1,2);
              delta_x = pow(R_x,2) + pow(G_x,2) + pow(B_x,2);
            }

            if (y<(im->height)-1 && y!=0){
              R_y = get_pixel(im, y+1,x,0) - get_pixel(im, y-1,x,0);
              G_y = get_pixel(im, y+1,x,1) - get_pixel(im, y-1,x,1);
              B_y = get_pixel(im, y+1,x,2) - get_pixel(im, y-1,x,2);
              delta_y = pow(R_y,2) + pow(G_y,2) + pow(B_y,2);
            }
            //if start of board
            if (x==0){
              R_x = get_pixel(im, y,x+1,0) - get_pixel(im, y,(im->width)-1,0);
              G_x = get_pixel(im, y,x+1,1) - get_pixel(im, y,(im->width)-1,1);
              B_x = get_pixel(im, y,x+1,2) - get_pixel(im, y,(im->width)-1,2);
              delta_x = pow(R_x,2) + pow(G_x,2) + pow(B_x,2);
            } 
            
            if (y==0){
              R_y = get_pixel(im, y+1,x,0) - get_pixel(im, (im->height)-1,x,0);
              G_y = get_pixel(im, y+1,x,1) - get_pixel(im, (im->height)-1,x,1);
              B_y = get_pixel(im, y+1,x,2) - get_pixel(im, (im->height)-1,x,2);
              delta_y = pow(R_y,2) + pow(G_y,2) + pow(B_y,2);   
            }

            //if end of board
            if (x == ((im->width)-1)){
              R_x = get_pixel(im, y,0,0) - get_pixel(im, y,x-1,0);
              G_x = get_pixel(im, y,0,1) - get_pixel(im, y,x-1,1);
              B_x = get_pixel(im, y,0,2) - get_pixel(im, y,x-1,2);
              delta_x = pow(R_x,2) + pow(G_x,2) + pow(B_x,2);
            } 

            if (y == ((im->height)-1)){
              R_y = get_pixel(im, 0,x,0) - get_pixel(im, y-1,x,0);
              G_y = get_pixel(im, 0,x,1) - get_pixel(im, y-1,x,1);
              B_y = get_pixel(im, 0,x,2) - get_pixel(im, y-1,x,2);
              delta_y = pow(R_y,2) + pow(G_y,2) + pow(B_y,2);
            }
        

        energy =  (float)(sqrt(delta_x+delta_y)/10);
        set_pixel(*grad, y,x, energy,energy,energy);//?????? NOT SURE WHAT TO PUT HERE
        
        }

    }

}
void dynamic_seam(struct rgb_img *grad, double **best_arr){
    *best_arr = (double *)malloc((grad->height) * (grad->width)* sizeof(double));

    //copies first row entry for entry
    for (int i = 0; i <grad->width; i++){
        (*best_arr)[0 * grad->width + i] = (double)(get_pixel(grad,0,i,1));//we can use 0 because recall we set all three 0,1,2 to be energy in calc_energy assignment at bottom.
    }

    for (int y = 1; y < (grad->height); y++){ //algorithm used: https://people.csail.mit.edu/mrub/talks/SeamCarving_6.865.pdf
        for (int x = 0; x < (grad->width); x++){
            if (x == 0){
                (*best_arr)[y * grad->width + x] = (double)(get_pixel(grad,y,x,0) + min_of_2((*best_arr)[(y-1)*grad->width + x], (*best_arr)[(y-1)*grad->width + x+1]));
            }
            else if (x==((grad->width)-1)){
                (*best_arr)[y * grad->width + x] = (double)(get_pixel(grad,y,x,0) + min_of_2((*best_arr)[(y-1)*grad->width + x], (*best_arr)[(y-1)*grad->width + x-1]));  
            }
            else{
                (*best_arr)[y * grad->width + x] = (double)(get_pixel(grad,y,x,0) + min_of_3((*best_arr)[(y-1)*grad->width + x], (*best_arr)[(y-1)*grad->width + x-1], (*best_arr)[(y-1)*grad->width + x+1]));    
            }
            

        }
    }
}
void print_dynamic_table(struct rgb_img *grad, double **best_arr){
    for (int y = 0; y < (grad->height); y++){ 
        for (int x = 0; x < (grad->width); x++){
            printf("%f ", (*best_arr)[y * grad->width + x]);
        }
        printf("\n");
    }
}
void recover_path(double *best, int height, int width, int **path){
    *path = (int *)malloc(sizeof(int)*height);

    //check the minimum in the bottom row
    double minimum = (best)[(height-1)*width + 0];
    int bottom_index = 0;
    for (int k = 0; k < width; k++){
        
        if ((best)[(height-1)*width + k] < minimum){
            minimum = (best)[(height-1)*width + k];
            bottom_index = k;
        }

    }
    (*path)[height-1] = bottom_index;
    int x = bottom_index;
    // printf("\nx:%d\n", x);
    //now work their way upwards
    for (int j = height-2; j>-1 ; j--){
        
        // printf("%f, %f, %f", (best)[(j)*width + x-1], (best)[(j)*width + x], (best)[(j)*width + x+1]);
        x = (*path)[j+1];
        if ((*path)[j+1] == 0){
            if ((best)[(j)*width + x] < (best)[(j)*width + x+1]){
                (*path)[j] = x;
            }
            else{
                (*path)[j] = x+1;
            }
        } 
        else if ((*path)[j+1] == width-1){
            if ((best)[(j)*width + x] < (best)[(j)*width + x-1]){
                (*path)[j] = x;
            }
            else{
                (*path)[j] = x-1;
            }
        }
        else{
            //if middle is smallest
            if ((best)[(j)*width + x] < min_of_2((best)[(j)*width + (x-1)], (best)[(j)*width + x+1])){
                (*path)[j] = x;
            }
            //otherwise
            else if ((best)[(j)*width + x+1] < (best)[(j)*width + (x-1)]){
                (*path)[j] = x+1;

            }
            else{
                (*path)[j] = x-1;
            }
    }
    // printf("   result[%d]: %f\n", (*path)[j], (best)[(j)*width + (*path)[j]]);
}}
void print_path(int **path, struct rgb_img *grad){
    printf("[");
    for (int i = 0; i < grad->height; i++){
        printf("%d, ", (*path)[i]);
    }
    printf("]");
}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, (src->width)-1);
    for (int y = 0; y < src->height; y++){
        int skip_index = 0;
        for (int x = 0; x < src->width; x++){
            if (x != path[y]){
                set_pixel(*dest,y,skip_index,get_pixel(src,y,x,0),get_pixel(src,y,x,1), get_pixel(src,y,x,2)) ;
                skip_index++;
                
            }
        }
    }

}


// int main() {
//     struct rgb_img *cur_im;
//     struct rgb_img *grad;
//     double *best;
//     int *path;

//     read_in_img(&cur_im, "6x5.bin");
//     calc_energy(cur_im,  &grad);
//     return
// }


int main(){
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 5; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);


        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);}
//     struct rgb_img *im;

//     struct rgb_img *cur_im;
//     struct rgb_img *grad;
//     double *best;
//     int *path;
  
//     read_in_img(&im, "HJoceanSmall.bin");
//     calc_energy(im,  &grad);    
//     // print_grad(grad);
//     dynamic_seam(grad,&best);
//     print_dynamic_table(grad, &best);
//     recover_path(best, grad->height, grad->width, &path);
//     // print_path(&path, grad);
//     remove_seam(im, &cur_im, path);

//     return 0;
