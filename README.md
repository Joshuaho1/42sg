# 42sg
My compiled work from the 42 school in Singapore. The main programming language used throughout this course is C. I have briefly summarized the projects I have completed below.

# Core
The main curriculum of 42.

## get_next_line
This function reads from a file descriptor and returns a line of text terminating in a newline character. Subsequent calls to the function return more lines within the file descriptor until there are no more lines. This project introduced static variables; my implementation used a static linked list for reading in the data. The `BUFFER_SIZE` (set at compilation time), which defines how many bytes are read at a time, determines how many nodes in the linked list are created. The function then parses through each node until a newline character is found and returns the text up to the newline.

## born2beroot
This project served as an introduction to Virtual Machines. Students were tasked with setting up a Virtual Machine in OracleVM, partitioning hard drive space for the VM using the Logical Volume Manager, configuring login and password policies, as well as setting up firewall and SSH. Students also deepened their understanding of shell commands (e.g., `sudo`, `root`) and scripts (e.g., monitoring services, `crontab`).

## ft_printf
A recreation of the standard `printf` function in C and an introduction to variadic functions. This version accepts the following specifiers:  
`%c` (char), `%s` (string), `%p` (pointer), `%d` (decimal), `%i` (integer), `%u` (unsigned integer), `%x` (hexadecimal lowercase), and `%X` (hexadecimal uppercase).  
The output and behavior of the function are similar to the original `printf`.

## Libft
The first project of the 42 curriculum was to recreate the C standard library of commonly used functions. This library includes functions like `ft_atoi.c` (convert an alphabetical string to an integer), `ft_split.c` (split a string into substrings based on a delimiter), linked list operating functions, and others.

# Piscine
This covers the work over the 26-day selection period known as the Piscine. It consists of several modules comprising the basics of C. Additionally, there are some group projects included as well.



