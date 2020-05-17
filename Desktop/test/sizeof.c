#include <stdio.h>
struct blist
{
        int cmd;
        int ip;
        char age;
        long time;
};

int main(int argc, char *argv[])
{

//        int *msg;
//        short *msg;
        struct blist *msg;
        int b=sizeof(*msg);
        int c=sizeof(msg);

        printf("b=%d c=%d\n", b, c);
		printf("%d\n", sizeof(msg->cmd));
		printf("%d\n", sizeof(msg->ip));
		printf("%d\n", sizeof(msg->age));
		printf("%d\n", sizeof(msg->time));
		printf("%d\n", sizeof(struct blist));

        return 0;

}
