module Parser where

import Debug.Trace
import Prelude hiding ((<*>), (<$>), (<*), (<$>), (*>), pure)

data Expr = Add Expr Expr
    | Sub Expr Expr
    | Mul Expr Expr
    | Div Expr Expr
    | Pow Expr Expr
    | Val Float

eval :: Expr -> Float
eval e = case e of
    Add a b -> eval a + eval b
    Sub a b -> eval a - eval b
    Mul a b -> eval a * eval b
    Div a b -> eval a / eval b
    Pow a b -> eval a ** eval b
    Val n   -> n


type Parser r = String -> Maybe (r, String)

pure :: a -> Parser a
pure x = \s -> Just (x, s)

(<$>) :: (a -> b) -> Parser a -> Parser b
f <$> p = \s -> case p s of
    Just (a, s') -> Just (f a, s')
    Nothing      -> Nothing

(<*>) :: Parser (a -> b) -> Parser a -> Parser b
p1 <*> p2 = \s -> case p1 s of
    Just (f, s') -> case p2 s' of
        Just (a, s'') -> Just (f a, s'')
        Nothing       -> Nothing
    Nothing -> Nothing

(<*) :: Parser a -> Parser b -> Parser a
p1 <* p2 = const <$> p1 <*> p2

(*>) :: Parser a -> Parser b -> Parser b
p1 *> p2 = (flip const) <$> p1 <*> p2

(<|>) :: Parser a -> Parser a -> Parser a
p1 <|> p2 = \s -> let r1 = p1 s in
    case r1 of
        Just _  -> r1
        Nothing -> p2 s

runParser :: Parser a -> String -> Maybe a
runParser p s = case p s of
    Just (r, "") -> Just r
    _            -> Nothing

list :: Parser a -> Parser [a]
list p = ((:) <$> p <*> list p) <|> pure []

emptyParen :: Parser a -> Parser [a]
emptyParen p = ((:) <$> p <*> list p)

check :: (Char -> Bool) -> Parser Char
check f = \s -> case s of
    (x:xs) | f x -> Just (x, xs)
    _            -> Nothing

parseChar :: Char -> Parser Char
parseChar c = check (== c)

parseString :: [Char] -> Parser Char
parseString cs = check (\c -> elem c cs)

parseNumber :: Parser Float
parseNumber = read <$> emptyParen digit
    where digit = parseString "0123456789."

expr :: Parser Expr
expr = add_sub
    where
        add_sub = binOp Add '+' parens expr <|> binOp Sub '-' parens expr <|> mul_div
        mul_div = binOp Mul '*' parens expr <|> binOp Div '/' parens expr <|> pow 
        pow = binOp Pow '^' parens expr <|> parens
        parens = (parseChar '(' *> expr <* parseChar ')') <|> val
        val = Val <$> parseNumber
        binOp c o p p2 = c <$> (p <* (parseChar o)) <*> p2

evalExpr :: String -> Maybe Float
evalExpr s = (fmap eval) $ runParser expr s

cleaner :: Char -> Char -> String -> String -> String
cleaner ' ' '-' s [] = cleaner '-' (head s) (tail s) "0-"
cleaner ' ' '+' s [] = cleaner '+' (head s) (tail s) "0+"
cleaner p c [] retS = (retS ++ [c])
cleaner p c s [] = cleaner c (head s) (tail s) [c]
cleaner '+' '+' s retS = cleaner '+' (head s) (tail s) retS
cleaner '*' '*' s retS = cleaner '*' (head s) (tail s) retS
cleaner '/' '/' s retS = cleaner '/' (head s) (tail s) retS
cleaner '^' '^' s retS = cleaner '^' (head s) (tail s) retS
cleaner '-' '-' s retS = cleaner '+' (head s) (tail s) ((init retS) ++ ['+'])
cleaner '+' '-' s retS = cleaner '-' (head s) (tail s) ((init retS) ++ ['-'])
cleaner '-' '+' s retS = cleaner '-' (head s) (tail s) ((init retS) ++ ['-'])
cleaner '(' '-' s retS = cleaner '-' (head s) (tail s) ((init retS) ++ "(0-")
cleaner '(' '+' s retS = cleaner '-' (head s) (tail s) ((init retS) ++ "(0+")
cleaner p c s retS = cleaner c (head s) (tail s) (retS ++ [c])