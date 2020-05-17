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

static int32_t temp=1500000;
static int32_t step=120000;

double datai[6000000] = {0};
double dataq[6000000] = {0};


//FILE *fd, *fdi, *fdq;

//FILE *fd[50];
//FILE (*fd)[3]; //error
FILE *fd0, *fd1, *fd2;

#endif /* SRC_SWEEP_H_ */
