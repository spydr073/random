-----------------------------------------------------------------------------------------[ Module ]
--{1
--                                                                              (\_/)
--                                                                              (o.O)
--                                                                              (> <)
--                                                                             #######
--                                                                           KILLER BUNNY
--                                                                             APPROVED
--
-- This module provides an interface generate random numbers using the PCG algorithm.
--

module System.Random.PCG

%dynamic   "./pcg_idris_ffi.so"

%default total
%access private

--}

------------------------------------------------------------------------------[ Primitive FFI API ]
--{1

||| Set a seed using to base integers.
public export
seed : Int -> Int -> IO ()
seed = foreign FFI_C "pcg_seed" (Int -> Int -> IO ())

||| Set a seed using system time.
public export
seedTime : IO ()
seedTime = foreign FFI_C "pcg_seedTime" (IO ())

||| Return a random unsigned integer.
public export
randInt : IO Int
randInt = foreign FFI_C "pcg_randInt" (IO Int)

||| Return a random unsigned integer.
public export
randNat : IO Int
randNat = foreign FFI_C "pcg_randNat" (IO Int)

||| Return a random unsigned integer within some upper bound.
public export
randBound : Int -> IO Int
randBound = foreign FFI_C "pcg_randBound" (Int -> IO Int)

||| Return a random float between 0 and 1 (exclusive).
public export
randFloat : IO Double
randFloat = foreign FFI_C "pcg_randFloat" (IO Double)

--}

-------------------------------------------------------------------------------[ Extended FFI API ]
--{1

||| Return a list of random numbers.
public export
randList : Num a => Nat -> IO a -> IO (List a)
randList n rand with (n)
  | Z    = pure []
  | S n' = sequence $ go n' [rand]
  where go : Num a => Nat -> List (IO a) -> List (IO a)
        go c xs with (c)
          | Z    = xs
          | S c' = go c' (rand :: xs)

--}



