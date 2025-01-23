set terminal pngcairo size 800,600 noenhanced
set datafile separator ','

fileBase = "f_test"
fileInput = fileBase.".csv"
fileOutput = fileBase.".png"

set xlabel "x"
set ylabel "y"
set title fileBase
set grid

set output fileOutput

plot fileInput us 1:2 w linespoints title "RK4", \
     fileInput us 1:3 w linespoints title "Adams-Moulton", \
     fileInput us 1:4 w linespoints title "Adams-Moulton Predictor-Corrector"
