set terminal pngcairo size 800,800
set output 'fractal_plot-01_01.png'
set pm3d map
set datafile separator " "
splot "fractal_data.csv" u 1:2:3
