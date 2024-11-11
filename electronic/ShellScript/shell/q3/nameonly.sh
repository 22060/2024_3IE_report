#!/bin/sh

filename=$1
echo $1 | awk '{printf("%s\n", index($0, "."))}' | awk '{printf("%s\n", substr("'$filename'", 0, $0-1))}'