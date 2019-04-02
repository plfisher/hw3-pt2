all:
		gcc -g prog1.c -lm -o fib
		gcc -g prog2.c -lm -o simple_shell

fib:
		gcc -g prog1.c -lm -o fib

sshell:
		gcc -g prog2.c -lm -o simple_shell
		
clean:
		rm practice



