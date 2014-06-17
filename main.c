#include "radio.h"

void W1 (int i){
	int j = 0;
	while (j < i){
            askHigh();
            usleep(500);
            askLow();
            usleep(500);
            j++;    
	}
}
void W2 (){
	int i = 0;
	while (i < 4){
                askHigh();
                usleep(1500);
                askLow();
                usleep(500);
                i++;
		}
}
int main (int argc, char **argv){
	setup_io();
	setup_fm();
	ACCESS(CM_GP0DIV) = (0x5a << 24) + 0x126B6;
	int cmd;
	switch (argv[1][0]){
		case 'f':
			cmd = 10;
			break;
		case 'b':
			cmd = 40;
			break;
		case 'a':
			cmd = 28;
			break;
		case 'd':
			cmd = 34;
			break;
		default:
			cmd = 0;
			break;
	}
	for (;;) {
		W2();
		W1(cmd);
	}
	return 0;
}
