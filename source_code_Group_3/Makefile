#####################################################################################################################################################
 #
 # [Authors]:(CCI, 2021) Group 3, [BAYA Ernest Kwame, BOUBAKAR Zourkalaini, JAWLA Haddy]
 # [Date]: Mon Jun 14, 2021 
 # [Goal]: automate the compilation and create an executable file named main.bin
 # [Execution]: /usr/bin/time -f '\t%E real([hours:]minutes:seconds),\t%U user(seconds),\t%S sys(seconds),\t%M memory(Kilobytes),\t%P cpu' ./main.bin 
 # [Version]: 1.3 (last version)
 # 
 ########################################################################################################################################################
CC = g++

all: main.bin
main.bin: main.o helpers.o
	@$(CC) -o $@ $^ -lpthread
%.o: %.cpp
	@$(CC) -c $< -lpthread

clean:
	@rm *.o
uninstall:
	@rm main.bin