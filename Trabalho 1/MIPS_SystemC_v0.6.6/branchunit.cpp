
// branchunit.cpp

#include "branchunit.h"

/**
 * \c branch unite module callback function.
 */
void branchunit::branch_detect()
{

    sc_uint<32> branchTarget_res;
    bool branchTaken_res;
    sc_uint<32> target32 = target.read();

    switch (opcode.read())
    {
       case 2:
              branchTaken_res = true;
              branchTarget_res = target32 | (PC4.read() & 0xF000);
              break;
       case 4:
              if(rs.read() == rt.read() && branch.read() == true){
                 branchTaken_res = true;
                 branchTarget_res = PC4.read() + (imm_ext.read()<<2);
              }
              break;
       case 5:
              if(rs.read() != rt.read() && branch.read() == true){
                branchTaken_res = true;
                branchTarget_res = PC4.read() + (imm_ext.read()<<2);
              }
              break;
       case 6:
              if(rs.read() <= 0 && branch.read() == true){
                branchTaken_res = true;
                branchTarget_res = PC4.read() + (imm_ext.read() << 2);
              }
              break;
       case 7:
              if(rs.read() > 0 && branch.read() == true){
                branchTaken_res = true;
                branchTarget_res = PC4.read() + (imm_ext.read() << 2);
              }
              break;
       case 8:
              branchTaken_res = true;
              branchTarget_res = rs.read();
              break;
    }

    branchTaken.write(branchTaken_res);
    branchTarget.write(branchTarget_res);
}
