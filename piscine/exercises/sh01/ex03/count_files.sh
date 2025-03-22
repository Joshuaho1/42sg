#!/bin/bash
find . -type f -or -type d | wc -l
# find . searches current direc and subdirecs
# -type f specifies files 
# -or is logical operator or
# type d specifies directories
# wc -l is count and with -l it counts the number of lines ouput by the find command

