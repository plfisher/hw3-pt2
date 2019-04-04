all:fib sshell sigblock

fib:
		gcc -g prog1.c -lm -o fib

sshell:
		gcc -g prog2.c -lm -o simple_shell
		
sigblock:
		gcc -g child.c -o child
		gcc -g prog3.c -lm -o shell
clean:
		rm practice



