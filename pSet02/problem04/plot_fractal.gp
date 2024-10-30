set terminal pngcairo size 1000,1000
set output 'fractal_plot-01_04.png'
set pm3d map
set datafile separator " "
splot "fractal_data.csv" u 1:2:3
