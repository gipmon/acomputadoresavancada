
// forward.cpp

#include "forward.h"

/**
 * \c forward unit module callback function.
 */
void forwardunit::forward_detect()
{
  rs_mux_id2.write(0);
  rt_mux_id2.write(0);
  rs_mux_exe.write(0);
  rt_mux_exe.write(0);
  mux_mem.write(0);

  //EXE/MEM->EXE(rs)
  //MEM/WB->EXE(rs)

  if(rs_exe.read()!=0 && rs_exe.read()==WriteReg_mem.read() && RegWrite_mem.read()==true){
    rs_mux_exe.write(1);
  }else if(rs_exe.read()!=0 && rs_exe.read()==WriteReg_wb.read() && RegWrite_wb.read()==true){
    rs_mux_exe.write(2);
  }
  //EXE/MEM->EXE(rt)
  //MEM/WB->EXE(rt)
  if(rt_exe.read()!=0 && rt_exe.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead_exe.read()==false){
    rt_mux_exe.write(1);
  }else if(rt_exe.read()!=0 && rt_exe.read()==WriteReg_wb.read() && RegWrite_wb.read()==true && MemRead_exe.read()==false){
    rt_mux_exe.write(2);
  }
  //EXE/MEM->ID2(rs) saltos
  //MEM/WB->ID2(rs)
  if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true){
    rs_mux_id2.write(1);
  }else if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_wb.read() && RegWrite_wb.read()==true){
    rs_mux_id2.write(2);
  }
  //EXE/MEM->ID2(rt) saltos
  //MEM/WB->ID2(rt)
  if(rt_id2.read()!=0 && rt_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read()==false){
    rt_mux_id2.write(1);
  }else if(rt_id2.read()!=0 && rt_id2.read()==WriteReg_wb.read() && RegWrite_wb.read()==true && MemRead.read()==false){
    rt_mux_id2.write(2);
  }

  //MEM/WB->MEM(rs)
  if(rt_mem.read()!=0 && rt_mem.read()==WriteReg_wb.read() && RegWrite_wb.read()==true && MemWrite_mem.read()==true){
    mux_mem.write(1);
  }

  // fprintf(stderr, "* rs_id2: %d\n", (int)rs_id2.read());
	// fprintf(stderr, "# rt_id2: %d\n", (int)rt_id2.read());
  // fprintf(stderr, "# WriteReg_exe: %d\n", (int)WriteReg_exe.read());
	// fprintf(stderr, "# WriteReg_mem: %d\n", (int)WriteReg_mem.read());
  // fprintf(stderr, "# branch: %d\n", (int)WriteReg_exe.read());
	// fprintf(stderr, "\n");
  // fprintf(stderr, "* rs_mux_id2: %d\n", (int)rs_mux_id2.read());
	// fprintf(stderr, "# rt_mux_id2: %d\n", (int)rt_mux_id2.read());
  // fprintf(stderr, "# rs_mux_exe: %d\n", (int)rs_mux_exe.read());
	// fprintf(stderr, "# rt_mux_exe: %d\n", (int)rt_mux_exe.read());
	// fprintf(stderr, "\n");

}
