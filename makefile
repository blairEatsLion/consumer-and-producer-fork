yy : main.o consumer.o producer.o
	gcc -o yy main.o consumer.o producer.o
consumer : main.o consumer.o
	gcc -o consumer main.o consumer.o
main.o : main.c
	gcc -c main.c

consumer.o : consumer.c
	gcc -c consumer.c

producer.o : producer.c
	gcc -c producer.c

clear :
	rm yy TURN.txt DATA.txt *.o

