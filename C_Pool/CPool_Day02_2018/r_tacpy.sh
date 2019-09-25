#!/bin/bash
sed '1~2d' | awk -F ":" '{ print $1 }' | rev | sed -n "$1,$2p" | sed ':a;N;$!ba;s/\n/, /g' | sed 's/$/.\n/' 
