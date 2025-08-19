#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpup=$(awk '/physical id/ {p=$4} /core id/ {print p ":" $4}' /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep processor /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free -m | awk '$1 == "Mem:" {print $2}')
ram_use=$(free -m | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), dis>
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf(">

# CPU LOAD
cpu_idle=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT
lastb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if lsblk | grep -q "lvm"; then echo "yes"; else echo "no"; fi)

# TCP CONNECT
tcpcon=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  Architecture: $arch
        CPU physical: $cpup
        vCPU: $cpuv
        Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
        Disk Usage: $disk_use/${disk_total} ($disk_percent%)
        CPU load: $cpu_fin%
        Last boot: $lastb
        LVM use: $lvmu
        Connections TCP: $tcpcon ESTABLISHED
        User log: $ulog
        Network: IP $ip ($mac)
        Sudo: $cmnd cmd"
