#!/bin/sh

today=$(date +%y%m%d)
filen='hoge.update'
filenew='/tmp/hogenew'
hogefile='hoge'
if [ ! -f $hogefile ]; then
    echo "This is hoge" > hoge
fi

if [ -f $filen ]; then
    echo "update already"
else
    cp hoge hoge.update
    cp hoge hoge.$today
    cp $filenew hoge
fi