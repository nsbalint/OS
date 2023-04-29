#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main()
{
	//ket descriptora van, ami a pipe ket veget jelenti(iro- es olvasoveget), igy ket elemu a "tomb"
	int pipe1[2];
	int pipe2[2];
	if(pipe(pipe1) == -1)
	{
		printf("Hiba tortent a cso letrehozasakor\n");
		// -1-el kilep mert hiba tortent
		exit(-1);
	}

	if(fork() == 0)
	{
		//gyerekprocessz
		//printf("Gyerekben: %d\n", a);
		//lezarjuk az iroveget
		close(pipe1[1]);
		char uzenetbuffer[8];
		char charbuf;
		//beolvassuk az uzenetet
		//read(pipe1[0], uzenetbuffer, 8);
		while(read(pipe1[0], &charbuf, 1) > 0)
		{
			strncat(uzenetbuffer, &charbuf, 1);
		}
		printf("Gyerek altal olvasott uzenet: %s\n", uzenetbuffer);
		close(pipe1[0]);

		//2.feladat
		char message[9];
                strcpy(message, "uzenet2\0");
                close(pipe2[0]);
                write(pipe2[1], message, strlen(message));
                printf("Gyerek elkuldte: %s\n", message);
                close(pipe2[1]);

	}
	else
	{
		//szuloprocess
		//printf("Szuloben: %d\n", a);
		//String a C-ben fos, igy karaktertombot kell letrehozni, es aztan strcpyvel feltolteni
		char message[8];
		strcpy(message, "uzenet\0");
		//close-al lezartuk a cso olvasoveget, hogy ne legyen tulcsordulas,  writeal pedig kiirattuk a dolgokat
		close(pipe1[0]);
		write(pipe1[1], message, strlen(message));
		printf("Szulo elkuldte: %s\n", message);
		//lezarjuk az iroveget is
		close(pipe1[1]);

                close(pipe2[1]);
                char uzenetbuffer[8];
                char charbuf;
                while(read(pipe2[0], &charbuf, 1) > 0)
                {
                        strncat(uzenetbuffer, &charbuf, 1);
                }
                printf("Szulo altal olvasott uzenet: %s\n", uzenetbuffer);
                close(pipe2[0]);

	}
}
