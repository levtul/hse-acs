#!/bin/bash

set -e

if [[ ! -f $1 ]]; then
    echo "Usage: ./run-tests.sh <binary>"
    exit 1
fi

binary=$1

run_test () {
  echo "========== RUNNING TEST $1 =========="
  /usr/bin/time -f "Memory: %M KB\nUser time: %U s\nKernel time: %S s" python3 "$binary" -f "tests/test$1.txt" "test_results/testResult$1.txt"
}

run_test 1
run_test 2
run_test 3
run_test 4
run_test 5
run_test 6
run_test 7
run_test 8
run_test 9
run_test 10
run_test 11
run_test 12
run_test 13
run_test 14
run_test 15
run_test 16
run_test 17
run_test 18
run_test 19
run_test 20
run_test EmptyInput
run_test MaxElemsCount
