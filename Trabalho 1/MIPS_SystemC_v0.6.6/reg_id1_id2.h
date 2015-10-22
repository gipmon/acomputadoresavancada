#ifndef REG_ID1_ID2_H
#define REG_ID1_ID2_H

/**
 *
 * reg_id1_id2_t module interface.
 */

#include <systemc.h>

#include "regT.h"

/**
 * reg_id1_id2_t module.
 * reg_id1_id2_t module is the ID/EXE pipeline register.
 */

SC_MODULE(reg_id1_id2_t) {

	// Ports

	sc_in  < bool > clk;
	sc_in  < bool > reset;
	sc_in  < bool > enable;

	sc_in  < sc_uint<32> > PC4_id;
	sc_out < sc_uint<32> > PC4_id2;

	sc_in  < sc_uint<16> > imm_id;
	sc_out < sc_uint<16> > imm_id2;

	sc_in  < sc_uint<5> > rt_id1, rd_id1;
	sc_out < sc_uint<5> > rt_id2, rd_id2;

	sc_in  < sc_uint<6> > opcode_id1, funct_id1;
	sc_out < sc_uint<6> > opcode_id2, opcode_id2;

	// sc_in  < sc_uint<32> > PC_id;   // only for visualization purposes
	// sc_out < sc_uint<32> > PC_exe;  // only for visualization purposes
	// sc_in  < bool > valid_id;       // only for visualization purposes
	// sc_out < bool > valid_exe;      // only for visualization purposes

	// Modules

	// regT < sc_uint<32> > *rega,*regb,*imm,*PC4;
	// regT < bool > *MemRead, *MemWrite, *MemtoReg, *Branch, *RegWrite, *ALUSrc;
	// regT < sc_uint<5> > *WriteReg;
	// regT < sc_uint<3> > *ALUOp;

	// regT < sc_uint<32> > *PC;      // only for visualization purposes
	// regT < bool > *valid;          // only for visualization purposes

	SC_CTOR(reg_id1_id2_t) {

		rega = new regT < sc_uint<32> > ("rega");;
		rega->din(rega_id);
		rega->dout(rega_exe);
		rega->clk(clk);
		rega->enable(enable);
		rega->reset(reset);

		regb = new regT < sc_uint<32> >("regb");
		regb->din(regb_id);
		regb->dout(regb_exe);
		regb->clk(clk);
		regb->enable(enable);
		regb->reset(reset);

		WriteReg = new regT < sc_uint<5> >("WriteReg");
		WriteReg->din(WriteReg_id);
		WriteReg->dout(WriteReg_exe);
		WriteReg->clk(clk);
		WriteReg->enable(enable);
		WriteReg->reset(reset);

		PC4 = new regT < sc_uint<32> >("PC4");
		PC4->din(PC4_id);
		PC4->dout(PC4_exe);
		PC4->clk(clk);
		PC4->enable(enable);
		PC4->reset(reset);

		imm = new regT < sc_uint<32> >("imm");
		imm->din(imm_id);
		imm->dout(imm_exe);
		imm->clk(clk);
		imm->enable(enable);
		imm->reset(reset);

		/*
		PC = new regT < sc_uint<32> >("PC");
		PC->din(PC_id);
		PC->dout(PC_exe);
		PC->clk(clk);
		PC->enable(enable);
		PC->reset(reset);

		valid = new regT < bool >("valid");
		valid->din(valid_id);
		valid->dout(valid_exe);
		valid->clk(clk);
		valid->enable(enable);
		valid->reset(reset);
		*/
	}
};

#endif
