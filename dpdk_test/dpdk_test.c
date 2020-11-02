#include <stdio.h>
#include <rte_eal.h>

int main(int argc, char** argv)
{
	if (rte_eal_init(argc, argv) != -1)
		printf("eal initialized\n");
	else
		printf("eal initialization failed\n");

	return 0;
}
