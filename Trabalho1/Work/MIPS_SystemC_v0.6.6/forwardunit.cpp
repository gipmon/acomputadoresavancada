
// forwardunit.cpp

#include "forwardunit.h"

/**
 * \c forward unit module callback function.
 */
void forwardunit::forward_detect()
{
  //DEFAULT
  rsmux_id2.write(0);
  rtmux_id2.write(0);
  rtmux_exe.write(0);
  rsmux_exe.write(0);

  //EXE/MEM->EXE(rs)
  if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true){
    rsmux_exe.write(1);
  }
  //EXE/MEM->EXE(rt)
  if(rt_id2.read()!=0 && rt_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read()==false){
    rtmux_exe.write(1);
  }
  //EXE/MEM->ID2(rs) saltos
  if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && branch.read()!=0){
    rsmux_id2.write(1);
  }
  //EXE/MEM->ID2(rt) saltos
  if(rt_id2.read()!=0 && rt_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && branch.read()!=0 && MemRead.read()==false){
    rtmux_id2.write(1);
  }
  //MEM/WB->EXE(rs)
  if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true){
    rsmux_exe.write(2);
  }
  //MEM/WB->EXE(rt)
  if(rt_id2.read()!=0 && rt_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read()==false){
    rtmux_exe.write(2);
  }
  //MEM/WB->ID2(rs) saltos
  if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && branch.read()!=0){
    rsmux_id2.write(2);
  }
  //MEM/WB->ID2(rt) saltos
  if(rt_id2.read()!=0 && rt_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && branch.read()!=0 && MemRead.read()==false){
    rtmux_id2.write(2);
  }
}
