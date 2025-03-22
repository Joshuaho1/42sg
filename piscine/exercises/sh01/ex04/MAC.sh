#!/bin/bash
ifconfig | awk '/ether/ {print $2}'
# ifconfig finds the network interfaces and details
# awk is a command used for pattern scanning, extraction, and manipulation
# in this case '/ether/ is used to search for the word ether
# {print $2 \n} prints the second field ($2) from ifconfig
 
