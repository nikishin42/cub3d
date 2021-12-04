#include <stdio.h>

unsigned long color_hex(int r, int g, int b)
{
	return ((r<<16) | (g<<8) | b); 
}

int main(void)
{
	printf("%lu\n", color_hex(255, 30, 0));
}