
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

	diff -y $file_name "$file_name.replace"
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
test "world" "welt"

print_test_case "one line without line break"
FILENAME="one_line_without_lb.txt"; CREATE=1; CONTENT="hello world"
setup_file
test "world" "welt"

print_test_case "one line with line break"
FILENAME="one_line.txt"; CREATE=1; CONTENT="hello world\n"
setup_file
test "world" "welt"

print_test_case "replace inner word"
FILENAME="replace_inner_word.txt"; CREATE=1; CONTENT="asdfworldadsf\n"
setup_file
test "world" "welt"

print_test_case "s1 is contained inside s2"
FILENAME="s1_in_s2.txt"; CREATE=1; CONTENT="here is a test\n"
setup_file
test "is" "here is what has been inserted"

print_test_case "bigger file"
FILENAME="big_text.txt";
test "is" "__"

print_test_case "even bigger file with garbage chars"
FILENAME="weird_chars.txt";
test "this_string_will_be_nowhere_I_am_just_checking_for_crash" "__"

rm "${TESTDIR}"/*.replace
