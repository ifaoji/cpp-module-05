CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
CPPFLAGS = 
LDFLAGS =
LDLIBS =

RAW_SRCS =	main \
			Bureaucrat \
			Form \

SRC_DIR = ./
SRCS = $(RAW_SRCS:%=$(SRC_DIR)/%.cpp)

OBJ_DIR = obj
OBJS = $(RAW_SRCS:%=$(OBJ_DIR)/%.o)
OBJ_DIRS := $(sort $(dir $(OBJS)))

NAME = form_up_maggots

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIRS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

$(OBJ_DIRS):
	mkdir -p $@
