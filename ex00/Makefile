NAME = megaphone

SRC = $(NAME).cpp

cc = g++ -std=c++98 -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(SRC)
	$(cc) $(SRC) -o $@

clean:
	rm -rf $(NAME).obj

fclean: clean
	rm -rf $(NAME)

re:	fclean all