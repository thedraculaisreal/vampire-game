#include <stdio.h>

int main()
{
    printf("Hello, World\n");

    static int max = 100;

    for(int i = 0; i < max; ++i)
    {
	printf("%d\n", i);

    }

    return 0;
}
