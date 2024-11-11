reset
set xrange [0:10000]
set grid
set xlabel "N"
set ylabel "m"
set term pdfcairo enhanced
set output "BubbleSort.pdf" 
plot "QuickSort.txt" us 1:2 t "Bubble Sort" w d
exit