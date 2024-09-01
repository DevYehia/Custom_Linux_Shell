SOURCE=$(wildcard *.c */*.c)
exec_file: $(SOURCE)
	gcc $(SOURCE) -o myShell