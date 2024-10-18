
#! /usr/bin/bash

TESTDIR="./testfiles"
FILENAME=""
CREATE=0
CONTENT=""

CBOLD="\033[1m"
CYELLOW="\033[33m"
CRESET="\033[0m"


test() {
	local	file_name="${TESTDIR}/${FILENAME}"
	local	s1=$1
	local	s2=$2

	# print setup
	printf "testing file: %s\ns1: %s\ns2: %s\n\n" $file_name "${s1}" "${s2}"

	./cheapSed $file_name "${s1}" "${s2}"

	diff -y --suppress-common-lines $file_name "$file_name.replace"
}

setup_file() {
	if [[ ${CREATE} -eq 1 ]]; then
		echo -e -n ${CONTENT} > "${TESTDIR}/${FILENAME}"
	fi
}

print_test_case() {
	printf "%s" "------------------------------------------------"
	printf "\n\n\n${CBOLD}${CYELLOW}%s${CRESET}\n" "$1"
}

mkdir -p ${TESTDIR}
make

print_test_case "non existing file"
FILENAME="non_existing.txt"; CREATE=0
setup_file
test "word" "___"

print_test_case "empty file"
FILENAME="empty_file.txt"; CREATE=1; CONTENT=""
setup_file
test "word" "___"

print_test_case "one line without line break"
FILENAME="one_line_without_lb.txt"; CREATE=1; CONTENT="this word"
setup_file
test "word" "___"

print_test_case "one line with line break"
FILENAME="one_line.txt"; CREATE=1; CONTENT="this word\n"
setup_file
test "word" "___"

print_test_case "replace inner word"
FILENAME="replace_inner_word.txt"; CREATE=1; CONTENT="asdfwordadsf\n"
setup_file
test "word" "___"

print_test_case "s1 is contained inside s2"
FILENAME="s1_in_s2.txt"; CREATE=1; CONTENT="here is a test\n"
setup_file
test "is" "____is____"

print_test_case "bigger file"
FILENAME="big_text.txt";
test "is" "__"

print_test_case "empty s1"
FILENAME="big_text.txt";
test "" "hello"

print_test_case "empty s2"
FILENAME="big_text.txt";
test "is" ""

print_test_case "empty strings"
FILENAME="big_text.txt";
test "" ""

print_test_case "same strings"
FILENAME="big_text.txt";
test "is" "is"

print_test_case "even bigger file with garbage chars"
FILENAME="weird_chars.txt";
test "this_string_will_be_nowhere_I_am_just_checking_for_crash" "__"

rm "${TESTDIR}"/*.replace
