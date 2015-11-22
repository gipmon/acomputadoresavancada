
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
    //
    // fprintf(stderr, "# branch rs: %#08x\n", (int)rs.read());
    // fprintf(stderr, "# branch rt: %#08x\n", (int)rt.read());
    // fprintf(stderr, "#branch: %d\n", (int)branch.read());

    switch (branch.read())
    {

       case 1:
              if(rs.read() == rt.read()){
                 branchTaken_res = true;
                 branchTarget_res = PC4.read() + (imm_ext.read()<<2);
              }else{
                branchTaken_res = false;
              }
              break;
       case 2:
              if(rs.read() != rt.read()){
                branchTaken_res = true;
                branchTarget_res = PC4.read() + (imm_ext.read()<<2);
              }else{
                branchTaken_res = false;
              }
              break;
      case 3:
           if((int)rs.read() > 0){
             branchTaken_res = true;
             branchTarget_res = PC4.read() + (imm_ext.read() << 2);
           }else{
             branchTaken_res = false;
           }
           break;
      case 4:
            if((int)rs.read() <= 0){
              branchTaken_res = true;
              branchTarget_res = PC4.read() + (imm_ext.read() << 2);
            }else{
              branchTaken_res = false;
            }
            break;
      case 5:
            //  fprintf(stderr, "# target: %#08x\n", (int)target32);
            //  fprintf(stderr, "# pc4: %#08x\n", (int)PC4.read());
             branchTaken_res = true;
			       branchTarget_res = target32 << 2 | (PC4.read() & 0xF000);
             break;
       case 6:
              branchTaken_res = true;
              branchTarget_res = rs.read();
              break;
       default:
              branchTaken_res = false;
              break;
    }
    // fprintf(stderr, "# branch res: %d\n", (int)branchTaken_res);
    branchTaken.write(branchTaken_res);
    branchTarget.write(branchTarget_res);
}
