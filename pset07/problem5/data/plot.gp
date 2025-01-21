set terminal pngcairo enhanced size 800,600
set datafile separator ','
set key left top

set xlabel 'log(h)'
set ylabel 'log(E)'

set grid

name1 = "function1"
name2 = "function2"
name3 = "function3"

# Plotting function1
set title "Function 1: Log of Error vs Log of Step Size"
set output name1.".png"
filein = name1.".csv"

plot filein us 2:3 w p title 'log(Etrap)', \
     filein us 2:4 w p title 'log(Esimp38)'


# Plotting function2
set title "Function 2: Log of Error vs Log of Step Size"
set output name2.".png"
filein = name2.".csv"

plot filein us 2:3 w p title 'log(Etrap)', \
     filein us 2:4 w p title 'log(Esimp38)'


# Plotting function3
set title "Function 3: Log of Error vs Log of Step Size"
set output name3.".png"
filein = name3.".csv"

plot filein us 2:3 w p title 'log(Etrap)', \
     filein us 2:4 w p title 'log(Esimp38)'
