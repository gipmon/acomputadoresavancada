#ifndef MUXFORWARD1_H
#define MUXFORWARD1_H

/**
 *
 * 3:1 Mux module template.
 */

#include <systemc.h>

/**
 * Mux module.
 * Mux module models a generic 2:1 multiplexor of template type T.
 * Implementation based on a template class.
 *
 *   - input ports
 *   	- \c T \c din0		- input
 *   	- \c T \c din1		- input
 *   	- \c bool \c sel		- select
 *   - output ports
 *   	- \c T \c dout		- output
 */

template <class T> class muxforward1: public sc_module
{
public:
  sc_in< T >  din0;
  sc_in< T >  din1;
  sc_in< T >  din2;
  sc_in< sc_uint<2> >  sel;
  sc_out< T > dout;

  SC_CTOR(muxforward1)
     {
      SC_METHOD(entry);
      sensitive << din0 << din1 << din2 << sel;
    }

  void entry();
};


template <class T> void muxforward1<T>::entry()
{
    if(sel.read() == 0) dout.write(din0.read());
    else if(sel.read() == 1) dout.write(din1.read());
    else dout.write(din2.read());

    fprintf(stderr, "MUX rt_id2");

    fprintf(stderr, "* sel: %d\n", (int)sel.read());
  	fprintf(stderr, "# din0: %d\n", (int)din0.read());
    fprintf(stderr, "# din1: %d\n", (int)din1.read());
  	fprintf(stderr, "# din2: %d\n", (int)din2.read());
    fprintf(stderr, "# dout: %d\n", (int)dout.read());
    fprintf(stderr, "\n");

}

#endif
