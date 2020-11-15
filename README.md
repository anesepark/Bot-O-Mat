# BOT-O-MAT ##

I decided to implement Bot-O-Mat using C++. The program assumes that the compiler used supports the <thread> header. I used the mingw-64 compiler with the thread options downloaded.

## Bot-O-Mat features: ##
 * Lets the user edit,delete, and add robots/task
    * Gives tasks a point system (ETA/100). Users can change the point value of a task if they choose.
 * Uses threads to run all robots at the same time
    * Gives the user a chance to input the time limit every robot has to complete all their tasks.
 * Keeps a leaderboard
 * Automatically saves leaderboard and tasks into their respective text files. Users are asked whether they want to save a list of robots as well.

## Linux OS ##
### Checking the version of g++:###
```bash
g++ --version
```

### Compiling the program would use the command:###
```bash
g++ -std=c++11 -o botomat -pthread Botomat.cpp Robot.cpp Robotlist.cpp TaskList.cpp Task.cpp
```

#### Note: If this gives you an error, try the flag -lpthread instead. ####

### To run:###
```bash
./botomat
```

## Mac OS ##

### Compiling the program would use the command: ###
```bash
clang++ --std=c++11 -stdlib=libc++ -llibc++ -lpthread -o foobar foobar.cpp
```

### To run: ###
```bash
./botomat
```

## Windows ##

### mingw-64 should be downloaded and added to environment variables. Please make sure to check off posix/pthreads. ###

###Compiling the program would use the command:###
```bash
g++ -std=c++11 -o botomat -pthread Botomat.cpp Robot.cpp Robotlist.cpp TaskList.cpp Task.cpp
```

Note: If this gives you an error, try the flag -lpthread instead.

To run:
```bash
./botomat
```
