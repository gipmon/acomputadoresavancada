git pull
make
cuda-memcheck sgm
cuda-memcheck testDiffs h_dbull.pgm d_dbull.pgm
