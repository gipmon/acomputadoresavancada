
#include "hazard.h"

/**
 * Callback for the hazard detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	// //data hazards
	// fprintf(stderr, "rs %d\n", (int) rs_id2.read());
	// fprintf(stderr, "rt %d\n", (int) rt_id2.read());
	// fprintf(stderr, "WriteReg_exe %d\n", (int) WriteReg_exe.read());
	// fprintf(stderr, "WriteReg_mem %d\n", (int) WriteReg_mem.read());
	// fprintf(stderr, "WriteReg_wb %d\n", (int) WriteReg_wb.read());

	if( 	 rs_id2.read()!=0 && rs_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	    || rs_id2.read()!=0 && rs_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
	    || rt_id2.read()!=0 && rt_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read() == false
	    || rt_id2.read()!=0 && rt_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read() == false
			|| rs_id2.read()!=0 && rs_id2.read()==WriteReg_wb.read() && RegWrite_wb.read()==true
			|| rt_id2.read()!=0 && rt_id2.read()==WriteReg_wb.read() && RegWrite_wb.read()==true && MemRead.read() == false)	 {


			// fprintf(stderr, "%s\n", "entrei");
			enable_pc.write(false);
			enable_ifid.write(false);
			enable_id1id2.write(false);
			enable_regs.write(false);
			reset_id2exe.write(true);

	}else {
	  enable_pc.write(true);
		enable_ifid.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);
		enable_regs.write(true);

		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_exmem.write(false);
		reset_ifid.write(false);
		reset_regs.write(false);

	}

	if(BranchTaken.read()==true){
			enable_pc.write(true);
			enable_ifid.write(true);
			reset_id1id2.write(true);
			reset_id2exe.write(true);
			reset_exmem.write(true);
			reset_ifid.write(true);
		}
	// control hazard

}
