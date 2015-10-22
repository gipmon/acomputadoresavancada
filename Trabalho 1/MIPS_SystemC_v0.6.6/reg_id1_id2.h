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

	sc_in  < sc_uint<32> > PC4_id1;
	sc_out < sc_uint<32> > PC4_id2;

	sc_in  < sc_uint<16> > imm_id1;
	sc_out < sc_uint<16> > imm_id2;

	sc_in  < sc_uint<5> > rt_id1, rd_id1;
	sc_out < sc_uint<5> > rt_id2, rd_id2;

	sc_in  < sc_uint<6> > opcode_id1, funct_id1;
	sc_out < sc_uint<6> > opcode_id2, funct_id2;

	// sc_in  < sc_uint<32> > PC_id;   // only for visualization purposes
	// sc_out < sc_uint<32> > PC_exe;  // only for visualization purposes
	// sc_in  < bool > valid_id;       // only for visualization purposes
	// sc_out < bool > valid_exe;      // only for visualization purposes

	// Modules

	regT < sc_uint<32> > *PC4;
	regT < sc_uint<16> > *imm;
	// regT < bool > *MemRead, *MemWrite, *MemtoReg, *Branch, *RegWrite, *ALUSrc;
	regT < sc_uint<5> > *rt, *rd;
	regT < sc_uint<6> > *opcode, *funct;

	// regT < sc_uint<32> > *PC;      // only for visualization purposes
	// regT < bool > *valid;          // only for visualization purposes

	SC_CTOR(reg_id1_id2_t) {

		rd = new regT < sc_uint<5> > ("rd");;
		rd->din(rd_id1);
		rd->dout(rd_id2);
		rd->clk(clk);
		rd->enable(enable);
		rd->reset(reset);

		rt = new regT < sc_uint<5> >("rt");
		rt->din(rt_id1);
		rt->dout(rt_id2);
		rt->clk(clk);
		rt->enable(enable);
		rt->reset(reset);

		opcode = new regT < sc_uint<6> >("opcode");
		opcode->din(opcode_id1);
		opcode->dout(opcode_id2);
		opcode->clk(clk);
		opcode->enable(enable);
		opcode->reset(reset);

		funct = new regT < sc_uint<6> >("funct");
		funct->din(funct_id1);
		funct->dout(funct_id2);
		funct->clk(clk);
		funct->enable(enable);
		funct->reset(reset);

		PC4 = new regT < sc_uint<32> >("PC4");
		PC4->din(PC4_id1);
		PC4->dout(PC4_id2);
		PC4->clk(clk);
		PC4->enable(enable);
		PC4->reset(reset);

		imm = new regT < sc_uint<16> >("imm");
		imm->din(imm_id1);
		imm->dout(imm_id2);
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
