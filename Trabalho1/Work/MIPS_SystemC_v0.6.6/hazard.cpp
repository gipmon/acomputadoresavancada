
#include "hazard.h"

static int i_hazard = 0;
/**
 * Callback for the hazard detection of \c hazard module.
 */
void hazard::detect_hazard()
{

	// fprintf(stderr, "--- detect_hazard  %d  ----\n", i_hazard++);

	//data hazards
	// if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	//     || rs_id2.read()!=0 && rs_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
	// 		|| rs_id2.read()!=0 && rs_id2.read()==WriteReg_wb.read() && RegWrite_wb.read() == true
	//     || rt_id2.read()!=0 && rt_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read() == false
	//     || rt_id2.read()!=0 && rt_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read() == false
	// 		|| rt_id2.read()!=0 && rt_id2.read()==WriteReg_wb.read() && RegWrite_wb.read() == true && MemRead.read() == false) {
	if(rs_id2.read()!=0 && rs_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead_exe.read()==true
	|| rt_id2.read()!=0 && rt_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead_exe.read() == true && MemRead.read()==false
	|| rs_id2.read()!=0 && rs_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && branch.read()!=0
	|| rt_id2.read()!=0 && rt_id2.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && branch.read()!=0 && MemRead.read()==false
	|| rs_id2.read()!=0 && rs_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && branch.read()!=0 && MemRead_mem.read()==true
	|| rt_id2.read()!=0 && rt_id2.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && branch.read()!=0 && MemRead.read()==false && MemRead_mem.read()==true){
		//fprintf(stderr, "if!\n");

		enable_pc.write(false);
		enable_ifid.write(false);
		enable_id1id2.write(false);
		enable_regs.write(false);
		reset_id2exe.write(true);
	}else if(BranchTaken.read()==true){
		fprintf(stderr, "BranchTaken entrou!\n");
		enable_pc.write(true);
		enable_ifid.write(true);
		reset_ifid.write(true);

		enable_id1id2.write(true);
		enable_id2exe.write(true);
		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_exmem.write(false);
		enable_regs.write(true);
		reset_regs.write(false);
	}else {
		// fprintf(stderr, "else!\n");
	  enable_pc.write(true);
		enable_ifid.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);
		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_exmem.write(false);
		reset_ifid.write(false);
		enable_regs.write(true);
		reset_regs.write(false);
	}

	// control hazard


	fprintf(stderr, "* BranchTaken: %d\n", (int)BranchTaken.read());
	fprintf(stderr, "\n");
	fprintf(stderr, "# rs: %d\n", (int)rs_id2.read());
	fprintf(stderr, "# rt: %d\n", (int)rt_id2.read());
	fprintf(stderr, "# WriteReg_exe: %d\n", (int)WriteReg_exe.read());
	fprintf(stderr, "# WriteReg_mem: %d\n", (int)WriteReg_mem.read());
	fprintf(stderr, "# RegWrite_exe: %d\n", (int)RegWrite_exe.read());
	fprintf(stderr, "# branch: %d\n", (int)branch.read());
	fprintf(stderr, "# MemRead_exe: %d\n", (int)MemRead_exe.read());
	fprintf(stderr, "# MemRead_mem: %d\n", (int)MemRead_mem.read());
	fprintf(stderr, "# MemRead: %d\n", (int)MemRead.read());
	fprintf(stderr, "\n");
	fprintf(stderr, "@ enable_pc: %d\n", (int)enable_pc.read());
	fprintf(stderr, "@ enable_ifid: %d\n", (int)enable_ifid.read());
	fprintf(stderr, "@ enable_id1id2: %d\n", (int)enable_id1id2.read());
	fprintf(stderr, "@ enable_id2exe: %d\n", (int)enable_id2exe.read());
	fprintf(stderr, "@ reset_id2exe: %d\n", (int)reset_id2exe.read());
	fprintf(stderr, "@ reset_exmem: %d\n", (int)reset_id2exe.read());
	fprintf(stderr, "@ reset_ifid: %d\n", (int)reset_id2exe.read());
	fprintf(stderr, "@ enable_regs: %d\n", (int)enable_regs.read());
	fprintf(stderr, "--- fim hazard ----\n");
}
