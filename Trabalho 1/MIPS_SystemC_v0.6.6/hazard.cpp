
#include "hazard.h"

/**
 * Callback for the hazard detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	//data hazards
	if( rs.read()!=0 && rs.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	    || rs.read()!=0 && rs.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
	    || rt.read()!=0 && rt.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read() ==false
	    || rt.read()!=0 && rt.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read() ==false) {

		enable_pc.write(false);
		enable_ifid.write(false);
		reset_id2exe.write(true);
	}else {
	  enable_pc.write(true);
		enable_ifid.write(true);
		reset_id2exe.write(false);
		reset_exmem.write(false);
		reset_ifid.write(false);
	}

	// control hazard
	if(BranchTaken.read()==true){
		enable_pc.write(true);
		enable_ifid.write(true);
		reset_id2exe.write(true);
		reset_exmem.write(true);
		reset_ifid.write(true);
	}
}
