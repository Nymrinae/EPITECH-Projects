path    =    $(shell stack path --local-install-root)

all:
	stack build
	cp $(path)/bin/evalexpr-exe ./funEvalExpr

clean:
	stack clean
	rm -f $(name)

fclean: clean

re: fclean all