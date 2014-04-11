-- Distributed and parallel technologies, Andrew Beveridge, 03/04/2014
-- To Compile:		ghc -Wall --make -threaded -cpp -O2 -rtsopts -o ab-totient-gph ab-totient-gph.hs
-- To Run / Time:	/usr/bin/time -v ./ab-totient-gph [range_start] [range_end] [threads] +RTS -N[threads]

module Main(main) where

import System.Environment
import System.IO
import Control.Parallel.Strategies

-- The main function, sumTotient  
-- 1. Generates a list of integers between min and max
-- 2. Applies totient function to every element of the list
-- 3. Returns the sum of the results

sumTotient :: Int -> Int -> Int -> Int
sumTotient min max threads = sum (
            (map euler ([min, min+1 .. max]) 
                `using` parListChunk (((max-min) `div` threads)+1) rdeepseq))

-- The euler n function
-- 1. Generates a list [1,2,3, ... n-1,n]
-- 2. Select only those elements of the list that are relative prime to n
-- 3. Returns a count of the number of relatively prime elements
euler :: Int -> Int
euler n = length (filter (relprime n) [1 .. n-1])

-- The relprime function returns true if it's arguments are relatively 
-- prime, i.e. the highest common factor is 1.
relprime :: Int -> Int -> Bool
relprime x y = hcf x y == 1

-- The hcf function returns the highest common factor of 2 integers
hcf :: Int -> Int -> Int
hcf x 0 = x
hcf x y = hcf y (rem x y)

---------------------------------------------------------------------------
-- Interface Section
---------------------------------------------------------------------------

main = do args <- getArgs
          let 
            min = read (args!!0) :: Int -- min limit of the interval
            max = read (args!!1) :: Int -- max limit of the interval
            threads = read (args!!2) :: Int -- Number of threads to be run on
          hPutStrLn stderr ("Sum of Totients between [" ++ 
                      (show min) ++ ".." ++ (show max) ++ "] is " ++ 
                       show (sumTotient min max threads) )
                       