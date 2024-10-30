set terminal pngcairo size 4000,4000
set output 'fractal_plot-01_03.png'
set pm3d map
set datafile separator " "
splot "fractal_data.csv" u 1:2:3
