COMPILE=gcc -Wall -Werror -Wextra -std=c11 -Wno-unused-parameter
TEST_LIBS=-lcheck -lm -lpthread -lrt -lsubunit
LIB_NAME=s21_matrix.a
PRGRM_NAME=test_s21_matrix
TEST_DIR=tests
TEST_FILES=$(TEST_DIR)/*.c $(TEST_DIR)/*/*.c
IMPL_FILES=arithmetic/s21_*.c comparsion/*.c create_delete/*.c special_OPs/*.c support/*.c
OBJ_FILES=s21_*.o


# Targets
all: gcov_report

compile: s21_matrix.a
	@$(COMPILE) $(TEST_FILES) $(TEST_LIBS) $(LIB_NAME) -o $(PRGRM_NAME)

test: compile
	@./$(PRGRM_NAME) || true

s21_matrix.a: $(IMPL_FILES)
	@$(COMPILE) -c $(IMPL_FILES)
	@ar -rcs $(LIB_NAME) $(OBJ_FILES)
	@rm -f $(OBJ_FILES)

add_coverage:
	@$(eval COMPILE+=--coverage)

gcov_report: add_coverage test
	@lcov -o tests.info -c -d .  
	@genhtml -o report tests.info
	@make clean


clean:
	@rm -f $(PRGRM_NAME) *.html *.css *.gcda *.gcno *.out *.info $(OBJ_FILES) $(LIB_NAME)
