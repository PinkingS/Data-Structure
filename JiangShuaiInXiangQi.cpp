#include <stdio.h>

#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b, n) (b = ((b & LMASK) | (n)))
#define LSET(b, n) (b = ((b & RMASK) | ((n) << HALF_BITS_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)
#define GRIDW 3

struct {
	unsigned char a:4;
	unsigned char b:4;
}i;

int main() {
/*
	unsigned char b;
	for(LSET(b, 1); LGET(b) <= GRIDW * GRIDW; LSET(b, (LGET(b)+1)))
		for(RSET(b, 1); RGET(b) <= GRIDW * GRIDW; RSET(b, (RGET(b)+1)))
			if(LGET(b) % 3 != RGET(b) % 3)
				printf("A=%d, B=%d\n",LGET(b), RGET(b));
*/

	for(i.a = 1; i.a <= 9; i.a++)
		for(i.b = 1; i.b <= 9; i.b++)
			if(i.a % 3 != i.b % 3)
				printf("A=%d, B=%d\n", i.a, i.b);
	printf("sizeof i : %d\n",sizeof(i));
	return 0;
}
