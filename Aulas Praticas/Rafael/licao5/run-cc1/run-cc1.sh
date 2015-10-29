SS_BIN_DIR=../simplesim-3.0
SS_EXEC_DIR=.
$SS_BIN_DIR/sim-bpred $* $SS_EXEC_DIR/cc1.ss -O1 $SS_EXEC_DIR/cb_ss.i -o /dev/null
