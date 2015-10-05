#CC1PLUS=/usr/lib/gcc-lib/i586-mandrake-linux/2.95.3/cc1plus 
CC1PLUS=./cc1plus 
MIPSIDIR=.
$CC1PLUS -quiet $* $MIPSIDIR/mips.i -o /dev/null
