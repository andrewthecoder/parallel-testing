---------------------------------------------------------------------------
-- Sequential Euler Totient Function 
---------------------------------------------------------------------------
-- This program calculates the sum of the totients between a lower and an 
-- upper limit, using arbitrary precision integers.
-- Phil Trinder, 26/6/03
-- Based on earlier work by Nathan Charles, Hans-Wolfgang Loidl and 
-- Colin Runciman
--
-- CW2 for F21DP by Konstantin Devyatov 7/3/14
--
-- To compile: ghc -v -O2 -prof -rtsopts -threaded -auto-all -caf-all -fforce-recomp -o ab-totient-haskell-kos ab-totient-haskell-kos.hs
-- To run: ab-totient-haskell-kos [lowerLimit] [upperLimit] +RTS -N[threads] -ls 
---------------------------------------------------------------------------

module Main(main) where

import System.IO
import System.Environment(getArgs)
import Control.Parallel 
import Control.Parallel.Strategies
import Control.DeepSeq
import GHC.Conc (numCapabilities)
import Data.Time.Clock (NominalDiffTime, diffUTCTime, getCurrentTime)
import Text.Printf

all_your_base :: Double
all_your_base = 1.57

getN :: Double -> Int
getN n = abs (floor (logBase all_your_base  n))

---------------------------------------------------------------------------
-- LogGroup
---------------------------------------------------------------------------
-- Groups list elements int a logarithmicly scaling groups

logGroup :: Double -> [Int] -> [[Int]]
logGroup m [] = []
logGroup m xs = (take n xs):( logGroup (m+1) (drop n xs) )
                        where n = getN m

---------------------------------------------------------------------------
-- Main Function, sumTotient
---------------------------------------------------------------------------
-- The main function, sumTotient  
-- 1. Generates a list of integers between lower and upper
-- 2. Applies Euler's phi function to every element of the list
-- 3. Returns the sum of the results

sumTotient :: [[Int]] -> Integer
sumTotient list = sum (map eulerB list `using` strat)
                    where strat = parList rdeepseq

--sumTotientNaive :: [Int] -> Integer
--sumTotientNaive list = sum (map euler list `using` strat)
--                    where strat = parListChunk 2 rdeepseq

eulerB :: [Int] -> Integer
eulerB [] = 0
eulerB xs = sum (map euler xs)

---------------------------------------------------------------------------
-- euler
---------------------------------------------------------------------------
-- The euler n function
-- 1. Generates a list [1,2,3, ... n-1,n]
-- 2. Select only those elements of the list that are relative prime to n
-- 3. Returns a count of the number of relatively prime elements

euler :: Int -> Integer
euler n = fromIntegral(length (filter (relprime n) [1 .. n-1]))

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
--mkList :: Integer -> Integer -> [Integer]
--mkList lower upper = reverse (enumFromTo lower upper)

---------------------------------------------------------------------------
-- Interface Section
---------------------------------------------------------------------------

main = do args <- getArgs
          let 
            lower = read (args!!0) :: Int -- lower limit of the interval
            upper = read (args!!1) :: Int -- upper limit of the interval
            list = logGroup all_your_base [upper, upper-1 .. lower]
            result = sumTotient list
          start <- getCurrentTime
          end <- result `deepseq` getCurrentTime

          printf "%.6f %d %d %u %.2f\n" (realToFrac (diffUTCTime end start) :: Double) upper result numCapabilities all_your_base
