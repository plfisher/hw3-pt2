all:
		gcc -g prog1.c -lm -o fib
		gcc -g prog2.c -lm -o simple_shell
		gcc -g prog3.c -lm -o shell

fib:
		gcc -g prog1.c -lm -o fib

sshell:
		gcc -g prog2.c -lm -o simple_shell
		
sigblock:
		gcc -g prog3.c -lm -o shell
clean:
		rm practice



