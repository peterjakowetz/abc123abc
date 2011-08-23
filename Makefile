CPPFLAGS = -g

default: sim

.PHONY: clean
clean:
	-@rm sim *.o

sim: sim_main.c sim_video.o sim_sensor.o sim_bot.o logic.h
	gcc $(CPPFLAGS) sim_video.o sim_sensor.o sim_main.c sim_bot.o -lSDL -lSDL_gfx -lSDL_image -o sim

sim_video.o: sim_video.c sim_video.h sim_bot.h
	gcc $(CPPFLAGS) -c sim_video.c -o sim_video.o

sim_sensor.o: sim_sensor.c sensor.h sim_bot.h
	gcc $(CPPFLAGS) -c sim_sensor.c -o sim_sensor.o

sim_bot.o: sim_bot.c sim_bot.h
	gcc $(CPPFLAGS) -c sim_bot.c -o sim_bot.o
