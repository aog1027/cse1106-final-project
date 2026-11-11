#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#include <stdbool.h>
#define PIN 17

int getTestNumber(void)
{
	int n;
	printf("Input number of tests you want to run: ");
	scanf("%d", &n);
	return n;
}

int getMemory(void)
{
	int p;
	printf("Input memory as a percentage: ");
	scanf("%d", &p);
	return p;
}

int getStorage(void)
{
	int p;
	printf("Input Storage Usage as a percentage: ");
	scanf("%d", &p);
	return p;
}

int main(int argc, char* argv[])
{
	int memory;
	int storage;
	int warningThreshold = 80;
	bool warning;
	bool loop = 1;
	gpioInitialise();
	gpioSetMode(PIN,PI_OUTPUT);
	
	gpioWrite(PIN,0);
	
	
	
	while(loop ==1)
	{
		int testNum = getTestNumber();
		printf("testNum: %d\n", testNum);
		
		for(int i = 0; i < testNum; i++)
		{
			memory = getMemory();
			storage = getStorage();
			if(memory >= warningThreshold || storage >= warningThreshold)
				warning = 1;
			else
				warning = 0;
			printf("Memory: %d\n", memory);
			printf("Storage: %d\n", storage);
			printf("Warning: %d\n", warning);
			gpioWrite(PIN,warning);
		}
		printf("Enter 1 to continue or 0 to exit: ");
		
		scanf("%d", &loop);
		
	}

		gpioWrite(PIN,0);
		gpioTerminate();
		return 0;
}
