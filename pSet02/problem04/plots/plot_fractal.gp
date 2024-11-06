set terminal pngcairo size 700,700
set output 'fractal_plot-01_16.png'
set pm3d map
set datafile separator ","
splot "./../data/fractal_data.csv" u 1:2:4
