SIM_CCFLAGS = -g
SIM_CC = gcc

CCFLAGS = -mmcu=atmega8 -Wall -Os
CC = avr-gcc

.PHONY: sim
default: sim main.hex

.PHONY: clean
clean:
	-@rm sim main.hex *.o

sim: sim_main.c sim_video.o sim_sensor.o sim_bot.o logic.h
	$(SIM_CC) $(SIM_CCFLAGS) sim_video.o sim_sensor.o sim_main.c sim_bot.o -lSDL -lSDL_gfx -lSDL_image -o sim

sim_video.o: sim_video.c sim_video.h sim_bot.h
	$(SIM_CC) $(SIM_CCFLAGS) -c sim_video.c -o sim_video.o

sim_sensor.o: sim_sensor.c sensor.h sim_bot.h
	$(SIM_CC) $(SIM_CCFLAGS) -c sim_sensor.c -o sim_sensor.o

sim_bot.o: sim_bot.c sim_bot.h
	$(SIM_CC) $(SIM_CCFLAGS) -c sim_bot.c -o sim_bot.o

bot.o: bot.c bot.h
	$(CC) $(CCFLAGS) -c bot.c -o bot.o

main.o: main.c logic.h bot.h bot.c
	$(CC) $(CCFLAGS) -c main.c -o main.o

main.elf: main.o bot.o
	$(CC) $(CCFLAGS) main.o bot.o -o main.elf

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
