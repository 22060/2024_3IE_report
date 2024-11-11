#!/bin/sh

filedir='/usr/*'
logfile='/tmp/dirducheck.$$'
echo "directory du check" > $logfile
echo "" >> $logfile
du -s $filedir | sort -nr >> $logfile
cat $logfile
mail -s "directory du check" example@hoge.mail < $logfile