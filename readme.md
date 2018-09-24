# PCG Random Number Generation
----------------------------------

Module provides bindings to PCG random numbers. The original PCG library has
been modified to interface with the Idris FFI system. Because of limitations in
the Idris packaging system, you will need to compile the PCG C file separately.
To install this package:

  1) cd src/cbits
  2) make
  3) cd ../../
  4) idris --install pcg_rand.ipkg



