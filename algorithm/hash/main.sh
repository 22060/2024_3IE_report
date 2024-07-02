#!/bin/bash

FILE_NAME=./dist.all.last.txt
while read LINE
do
# コマンド
echo ${LINE} | awk '{print $1}'
done < ${FILE_NAME}

