OBJFILES = writehex.o writeint.o writepercent.o writetext.o ft_printf.o main.o

all: writehex writeint writepercent writetext ft_printf main clean

run: print_app
	./print_app

clean:
	rm -f $(OBJFILES)

main: main.c
	cc main.c -c
	cc -o print_app $(OBJFILES)

ft_printf: ft_printf.c
	cc ft_printf.c -c

writehex: writehex.c
	cc writehex.c -c

writeint: writeint.c
	cc writeint.c -c

writepercent: writepercent.c
	cc writepercent.c -c

writetext: writetext.c
	cc writetext.c -c
