#ifndef BRANCHUNIT_H
#define BRANCHUNIT_H

/**
 *
 * BRANCH UNIT module interface.
 */

#include <systemc.h>

/**
 * ALU module.
 * ALU module models the integer ALU of the MIPS. It can perform 6 operations:
 * %add, subtract, %and, or, set on equal
 *   - input ports
 *   	- \c sc_uint<32> \c din1	- first operand
 *   	- \c sc_uint<32> \c din2	- second operand
 *   	- \c sc_uint<3>  \c op	- selects operation
 *   - output ports
 *   	- \c sc_unint<32> \c dout	- result
 *   	- \c bool         \c zero	- active if result = 0
 */

SC_MODULE(branchunit) {

  sc_in< sc_uint<32> >  imm_ext, PC4;
  sc_in< sc_uint<26> >  target;
  sc_in< sc_uint<32> >  rs, rt;
  sc_in< sc_uint<6> > opcode;
  sc_in< sc_uint<3> > branch;
  sc_out< bool > branchTaken;
  sc_out< sc_uint<32> > branchTarget;

  SC_CTOR(branchunit)
     {
      SC_METHOD(branch_detect);
      sensitive << imm_ext << PC4 << target << rs
      << rt << opcode << branch;
    }

  void branch_detect();
};

#endif
