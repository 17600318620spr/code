#ifndef SRC_SWEEP_H_
#define SRC_SWEEP_H_

#define PI 3.1415926

int timer = 0;

typedef int int32_t;
static int32_t T = 1;
static int32_t B = 3000000;
static int32_t Fs = 6000000;
static int32_t Ts;
static int32_t K ;

//double datai[6000000] = {0};
//double dataq[6000000] = {0};

double datai[130000] = {0};
double dataq[130000] = {0};

FILE *fd, *fdi, *fdq;


#endif /* SRC_SWEEP_H_ */
