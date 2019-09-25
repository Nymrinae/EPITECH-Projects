#!/bin/bash
if [ $# == 0 ]
then
	grep -c  "***"
else
	grep -i $1 -wc
fi
