#ifndef FORWARDUNIT_H
#define FORWARDUNIT_H

/**
 *
 * FORWARD UNIT module interface.
 */

#include <systemc.h>

SC_MODULE(forwardunit) {

  sc_in< sc_uint<5> > rs_id2, rt_id2;
  sc_in< sc_uint<5> > WriteReg_exe, WriteReg_mem;
  sc_in< bool > RegWrite_exe, RegWrite_mem, MemRead;
  sc_in< sc_uint<3> > branch;
  sc_out< sc_uint<2> > rsmux_exe, rtmux_exe, rsmux_id2, rtmux_id2;

  SC_CTOR(forwardunit)
     {
      SC_METHOD(forward_detect);
      sensitive << rs_id2 << rt_id2 << WriteReg_exe << WriteReg_mem
      << branch << RegWrite_exe << RegWrite_mem << MemRead;
    }

  void forward_detect();
};

#endif
