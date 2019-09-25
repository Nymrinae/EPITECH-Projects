#!/bin/bash
awk -F":" '{print $5}' | awk -F" " '{print $2}' | grep -c "^$1"
