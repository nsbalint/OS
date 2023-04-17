#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
// nano <forrasfilename.c>
// gcc <forrasfilename.c> -o <outputfilename>
// ./<outputfilename>

//Sima Hello World oyeah
	printf("Hello World\n\n");
//PID = process ID, a processznek az ID-ját adja meg
	int pid = getpid();
	printf("Az en processz id-m: %d\n", pid);
//PPID = parent process ID, a processz szuloprocesszenek az ID-ját adja meg
	int ppid = getppid();
	printf("A processz szuloprocesszenek ID-ja: %d\n\n", ppid);
//fork(), egy gyerekprocesszet hoz letre
//letrehoztuk a proba valtozot,amivel megnezzuk hogy a fork altal levalasztott processzek mas eredmenyt fognak kiirni
	int proba = 0;
	int forkreturn = fork();
	if(forkreturn == 0)
	{
		printf("Gyerek processz PID: %d PPID: %d\n", getpid(), getppid());
		printf("%d\n", proba);
		if(fork() == 0)
		{
			printf("\nUnokaprocessz PID: %d PPID: %d\n", getpid(), getppid());
			printf("%d\n", proba);
		}
	}
	else
	{
		printf("Ez a szuloprocessz PID: %d PPID: %d\n", getpid(), getppid());
		proba = 15;
                printf("%d\n", proba);
                if(fork() == 0)
                {
                        printf("\nMasik gyerek processz PID: %d PPID: %d\n", getpid(), getppid());
			printf("%d\n", proba);

                }

	}
//ezt mindegyik fuggveny kifogja irni
	printf("Itt a vege PID: %d\n", getpid());
	proba = 50; //igy mindegyik proba ertek 50 lesz(kinda)
        printf("%d\n", proba);

	return 0;
}
