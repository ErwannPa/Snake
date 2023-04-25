CC=gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3
MLV1=`pkg-config --cflags MLV`
MLV2=`pkg-config --libs-only-other --libs-only-L MLV`
MLV3=`pkg-config --libs-only-l MLV`


main: sauvegarde.o pomme.o serpent.o initialisation.o mlv.o main.o
	$(CC) $(OPTIONS)  $(MLV1) $(MLV2) sauvegarde.o pomme.o serpent.o initialisation.o mlv.o main.o -o main $(MLV3)

main.o: main.c main.h
	$(CC) $(OPTIONS) $(MLV1) $(MLV2) -c main.c $(MLV3)

mlv.o: mlv.c mlv.h
	$(CC) $(OPTIONS) $(MLV1) $(MLV2) -c mlv.c $(MLV3)

initialisation.o: initialisation.c initialisation.h
	$(CC) $(OPTIONS) $(MLV1) $(MLV2) -c initialisation.c $(MLV3)

serpent.o: serpent.c serpent.h
	$(CC) $(OPTIONS) -c serpent.c

pomme.o: pomme.c pomme.h
	$(CC) $(OPTIONS) -c pomme.c

sauvegarde.o: sauvegarde.c sauvegarde.h
	$(CC) $(OPTIONS) -c sauvegarde.c 

clean:
	rm  *.o *~ main