CC = $(CLANG_PREFIX)clang
LAB_OPTS = -I./src src/lib.c
C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes --undef-value-errors=yes --track-origins=no --child-silent-after-fork=no --trace-children=no --error-exitcode=1

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
test.bin: test/test.c
	$(CC) $(C_OPTS) $< $(ARCH) -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -lcheck
test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	$(CLANG_PREFIX)llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	$(CLANG_PREFIX)llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	$(CLANG_PREFIX)llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
check:
	clang-format --verbose -dry-run --Werror src/* test/*
	$(CLANG_PREFIX)clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/main.c --suppress=knownConditionTrueFalse:*/main.c --suppress=missingIncludeSystem  --check-config --suppress=*:*/test.c  --suppress=unmatchedSuppression:*/main.c .
	rm -rf src/*.dump test/*.dump
leak-check: clean prep compile
	valgrind $(V_FLAGS) --log-file=dist/valgrind.log --xml-file=dist/valgrind.xml --xml=yes dist/main.bin
	valgrind $(V_FLAGS) --log-file=dist/valgrind.log --xml-file=dist/valgrind.xml --xml=yes dist/test.bin
