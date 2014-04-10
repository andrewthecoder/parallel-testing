-- Distributed and parallel technologies, Andrew Beveridge, 03/03/2014
-- To Compile:		ghc -Wall --make -threaded -cpp -O2 -rtsopts -o ab-totient-gph ab-totient-gph.hs
-- To Run / Time:	/usr/bin/time -v ./ab-totient-gph [range_start] [range_end] [cores] +RTS -N[cores]

module Main(main) where

import System.Environment
import System.IO
import Control.Parallel.Strategies

-- The main function, sumTotient  
-- 1. Generates a list of integers between lower and upper
-- 2. Applies totient function to every element of the list
-- 3. Returns the sum of the results

sumTotient :: Int -> Int -> Int -> Int
sumTotient lower upper cores = sum (
            (map euler ([lower, lower+1 .. upper]) 
                `using` parListChunk (((upper-lower) `div` cores)+1) rdeepseq))

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
            lower = read (args!!0) :: Int -- lower limit of the interval
            upper = read (args!!1) :: Int -- upper limit of the interval
            cores = read (args!!2) :: Int -- Number of cores to be run on
          hPutStrLn stderr ("Sum of Totients between [" ++ 
                      (show lower) ++ ".." ++ (show upper) ++ "] is " ++ 
                       show (sumTotient lower upper cores) )
                       