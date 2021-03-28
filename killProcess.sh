#!/bin/bash
# Author: Manar Al-Kali

# ask the user for the process to kill
read -p "which process want to kill: " TOKILL

kill $(ps aux| grep $TOKILL | grep -v grep | awk '{ print $2 }')

echo "process done sucessfully!"

exit 0
