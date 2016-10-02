#include "header.h"

int CariFPB(int a, int b) {
	if(b==0)
		return a;
	else {
		int temp = a % b;
		return CariFPB(b, temp);
	}
}