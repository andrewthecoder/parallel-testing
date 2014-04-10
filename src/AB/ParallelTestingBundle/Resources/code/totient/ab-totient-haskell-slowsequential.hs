
---------------------------------------------------------------------------
-- Sequential Euler Totient Function 
---------------------------------------------------------------------------
-- This program calculates the sum of the totients between a lower and an 
-- upper limit, using arbitrary precision integers.
-- Phil Trinder, 26/6/03
-- Based on earlier work by Nathan Charles, Hans-Wolfgang Loidl and 
-- Colin Runciman
-- To compile: ghc -O2 -rtsopts -prof -auto-all -o ab-totient-haskell-slowsequential ab-totient-haskell-slowsequential.hs
---------------------------------------------------------------------------

module Main(main) where

import System.Environment
import System.IO

---------------------------------------------------------------------------
-- Main Function, sumTotient
---------------------------------------------------------------------------
-- The main function, sumTotient  
-- 1. Generates a list of integers between lower and upper
-- 2. Applies Euler's phi function to every element of the list
-- 3. Returns the sum of the results

sumTotient :: Int -> Int -> Int
sumTotient lower upper = sum (map euler [lower, lower+1 .. upper])

---------------------------------------------------------------------------
-- euler
---------------------------------------------------------------------------
-- The euler n function
-- 1. Generates a list [1,2,3, ... n-1,n]
-- 2. Select only those elements of the list that are relative prime to n
-- 3. Returns a count of the number of relatively prime elements

euler :: Int -> Int
euler n = length (filter (relprime n) [1 .. n-1])

---------------------------------------------------------------------------
-- relprime
---------------------------------------------------------------------------
-- The relprime function returns true if it's arguments are relatively 
-- prime, i.e. the highest common factor is 1.

relprime :: Int -> Int -> Bool
relprime x y = hcf x y == 1

---------------------------------------------------------------------------
-- hcf 
---------------------------------------------------------------------------
-- The hcf function returns the highest common factor of 2 integers

hcf :: Int -> Int -> Int
hcf x 0 = x
hcf x y = hcf y (rem x y)

---------------------------------------------------------------------------
-- mkList
---------------------------------------------------------------------------
-- enumerate the interval in reverse order
mkList :: Int -> Int -> [Int]
mkList lower upper = reverse (enumFromTo lower upper)

---------------------------------------------------------------------------
-- Interface Section
---------------------------------------------------------------------------

main = do args <- getArgs
          let 
            lower = read (args!!0) :: Int -- lower limit of the interval
            upper = read (args!!1) :: Int -- upper limit of the interval
          hPutStrLn stderr ("Sum of Totients between [" ++ 
                      (show lower) ++ ".." ++ (show upper) ++ "] is " ++ 
                       show (sumTotient lower upper))
                       