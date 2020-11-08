module Main where

import System.Environment
import System.Exit
import Text.Printf
import Parser
import Debug.Trace

main :: IO ()
main = do
    args <- getArgs
    if (length args == 1 && length (head args) > 0) then do
        -- putStrLn (cleaner ' ' (head (head args)) (tail (head args)) [])
        let str = strip " \t" (head args)
        if ((parseNumber str) /= Nothing || tail str /= []) then
            myPrint (evalExpr (cleaner ' ' (head str) (tail str) []))
        else do
            exitWith $ ExitFailure 84 
            -- myPrint (evalExpr (cleaner ' ' (head str) (tail str) []))
        -- if (ret == Infinity || ret == Nothing) then
        --     exitWith $ ExitFailure 84
        -- else do
        --     myPrint ret
        --     exitWith $ ExitSuccess 0
        -- myPrint (evalExpr (strip " \t" (head args)))
    else
        exitWith $ ExitFailure 84

strip :: String -> String -> String
strip = filter . flip notElem


myPrint :: (Show a, PrintfArg a, RealFloat a) => Maybe a -> IO ()
myPrint (Just x) = 
    if (not (isInfinite x)) then
        printf "%.2f\n" x
    else do
        print x
        exitWith $ ExitFailure 84
myPrint n        = do 
    print n
    exitWith $ ExitFailure 84
