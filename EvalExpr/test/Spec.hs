import Test.Hspec
import Test.QuickCheck
import Data.Either (isLeft)
import Parser


main :: IO ()
main = hspec $do
    describe "Nothing" $ do
        it "parse `` = Nothing" $ do
            evalExpr "" `shouldBe` Nothing
    describe "Empty paren" $ do
        it "parse () = Nothing" $ do
            evalExpr "()" `shouldBe` Nothing
    describe "non-number" $ do
        it "parse é = Nothing" $ do
            evalExpr "é" `shouldBe` Nothing

    describe "add" $ do
        it "parse `1+2` = 3" $ do
            evalExpr "1+2" `shouldBe` (Just 3)
    describe "sub" $ do
        it "parse `1-2` = -1" $ do
            evalExpr "1-2" `shouldBe` (Just (-1))
    describe "mul" $ do
            it "parse `2*2` = 4" $ do
                evalExpr "2*2" `shouldBe` (Just 4)
    describe "div" $ do
        it "parse `4/2` = 2" $ do
            evalExpr "4/2" `shouldBe` (Just (2))
    describe "pow" $ do
        it "parse `4^2` = 16" $ do
            evalExpr "4^2" `shouldBe` (Just (16))

    describe "multiple add" $ do
        it "parse 3+3+3 = 9" $ do
            evalExpr "3+3+3" `shouldBe` (Just (9))
    describe "multiple sub" $ do
        it "parse 3-3-3 = -3" $ do
            evalExpr "3-3-3" `shouldBe` (Just (-3))
    describe "multiple mul" $ do
        it "parse 3*3*3 = 27" $ do
            evalExpr "3*3*3" `shouldBe` (Just (27))
    describe "multiple div" $ do
        it "parse 20/2/2 = 5" $ do
            evalExpr "20/2/2" `shouldBe` (Just (5))
    describe "multiple pow" $ do
        it "parse 3^2^2 = 81" $ do
            evalExpr "3^2^2" `shouldBe` (Just (81))

    describe "Parens" $ do
        it "parse (3+3)*2 = 12" $ do
            evalExpr "(3+3)*2" `shouldBe` (Just (12))
    describe "Negative" $ do
        it "parse -3 = -3" $ do
            let str = "-3"
            evalExpr (cleaner ' ' (head str) (tail str) []) `shouldBe` (Just (-3))