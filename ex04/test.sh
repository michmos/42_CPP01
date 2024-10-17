
#! /usr/bin/bash

TESTDIR="./testfiles"


test() {
	local	file_name="${TESTDIR}/$1"
	local	s1=$2
	local	s2=$3

	# print setup
	printf "testing file: %s\ns1: %s\ns2: %s\n\n" $file_name $s1 $s2

	./src/./a.out $file_name $s1 $s2

	printf "result\n\n"
	diff -y $file_name "$file_name.replace"
}

setup_file() {
	local	create=$1
	local	file_name="${TESTDIR}/$2"
	local	input=$3

	if [[ $create -eq 1 ]]; then
		echo $input > $file_name
	fi
}

mkdir -p ${TESTDIR}

setup_file 1 "one_line" "hello world"
test "one_line" "world" "welt"

# rm -rf ${TESTDIR}


# test("nonExistingFile");
#
# $FILENAME = ${TESTDIR}/"emptyFile"
# touch "${FILENAME}"
# test("${FILENAME}")
#
# $FILENAME = ${TESTDIR}/"oneLineWithoutNL"
# touch "${FILENAME}"
# echo -n "0123456789" > "${FILENAME}"
# test("${FILENAME}");
#
# $FILENAME = ${TESTDIR}/"oneLineWithNL"
# touch "${FILENAME}"
# echo "0123456789" > "${FILENAME}"
# test("${FILENAME}");
#
# $FILENAME = ${TESTDIR}/"multipleLines"
# touch "${FILENAME}"
# echo "Hello World\nWorld Hello\nHeWorldlo" > "${FILENAME}"
# test("${FILENAME}");
#
# $FILENAME = ${TESTDIR}/"bigFile"
# touch "${FILENAME}"
# echo "Hello World\nWorld Hello\nHeWorldlo" > "${FILENAME}"
# test("${FILENAME}");
