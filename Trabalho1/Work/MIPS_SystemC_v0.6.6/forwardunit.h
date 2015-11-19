#ifndef FORWARDUNIT_H
#define FORWARDUNIT_H

/**
 *
 * FORWARD UNIT module interface.
 */

#include <systemc.h>

SC_MODULE(forwardunit) {

  sc_in< sc_uint<5> > rs_id2, rt_id2, rs_exe, rt_exe, rs_mem, rt_mem;
  sc_in< sc_uint<5> > WriteReg_exe, WriteReg_mem, WriteReg_wb;
  sc_in< bool > RegWrite_exe, RegWrite_mem, RegWrite_wb, MemRead, MemRead_exe, MemRead_mem, MemRead_wb, MemWrite_mem;
  sc_in< sc_uint<3> > branch;
  sc_out< sc_uint<2> > rs_mux_exe, rt_mux_exe, rs_mux_id2, rt_mux_id2;
  sc_out< bool > mux_mem;

  SC_CTOR(forwardunit)
     {
      SC_METHOD(forward_detect);
      sensitive << rs_id2 << rt_id2 << rs_exe << rt_exe
      << rs_mem << rt_mem << WriteReg_exe << WriteReg_mem
      << WriteReg_wb << RegWrite_wb << MemRead_mem << MemRead_wb << MemWrite_mem
      << branch << RegWrite_exe << RegWrite_mem << MemRead << MemRead_exe;
    }

  void forward_detect();
};

#endif
