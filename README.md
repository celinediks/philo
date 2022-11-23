# # Philosophers
Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

## Project description
<p>Subject document of the project: <a href="philosophers_subject.pdf" target="_blank">philosophers</a></p>
Philosophers is a project that learned me how to work with threads and mutexes. 
Each part of a multithreaded program is called a thread, and each thread defines a separate path of execution. 
Mutexes make sure that variables don't get set or read by different threads at the same time.

### Norm writing
This project is written in accordance to the norm of school 42. Some of the most important norm rules are:
- Each function has a maximum of 25 lines
- One single variable declaration per line, all variables on top of the function 
- After the variable declarations, a newline will split them with the rest of the function
- No for loops allowed


## Install and run the project

First, clone my repository on your computer via the green "code" button on top of this page.
All the functions can be compiled using my Makefile. This Makefile has several options:
- run <code>make</code> to create object files for all the standard functions.
- run <code> ./philo </code> followed by 4 integers separated by a space which represent: 
 1. number_of_philosophers 
 2. time_to_die 
 3. time_to_eat 
 4. time_to_sleep 
 5. number_of_times_each_philosopher_must_eat (optional)
- run <code>make clean</code> to delete all the object files
- run <code>make fclean</code> to delete all the object files and the printf.a file.
- run <code>make re</code> recompile the library.
