OBJFILES = writehexs.o writeints.o writepercent.o writetext.o ft_printf.o main.o

all: writehexs writeints writepercent writetext ft_printf main clean

clean: 
	rm -f $(OBJFILES)

main: main.c
	cc main.c -c
	cc -o print_app writehexs.o writeints.o writepercent.o writetext.o ft_printf.o main.o 

ft_printf: ft_printf.c
	cc ft_printf.c -c


writehexs: writehexs.c
	cc writehexs.c -c


writeints: writeints.c
	cc writeints.c -c


writepercent: writepercent.c
	cc writepercent.c -c


writetext: writetext.c
	cc writetext.c -c
