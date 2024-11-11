#! /bin/csh

set today = `date +%y%m%d`
set filen = 'hoge.update'
set filenew = '/tmp/hogenew'
set hogefile = 'hoge'
if (! -f $hogefile ) then
    echo "This is hoge" > hoge
endif

if ( -f $filen ) then
    echo "update already"
else
    cp hoge hoge.update
    cp hoge hoge.$today
    cp $filenew hoge
endif
