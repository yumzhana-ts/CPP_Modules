#!/bin/bash

echo "== Running PmergeMe from 1 to 20 numbers =="

test_cases=(
  "5"
  "1 3"
  "2 0 1"
  "3 2 1 0"
  "9 8 7 6 5"
  "3 1 4 1 5 9"
  "7 6 5 4 3 2 1"
  "10 9 8 7 6 5 4 3"
  "4 5 4 3 2 1 1 2 3"
  "5 6 7 8 9 10 9 8 7 6"
  "1 3 5 7 9 8 6 4 2 0 10"
  "5 4 3 2 1 10 9 8 7 6 0 11"
  "8 9 10 7 6 5 4 3 2 1 0 11 12"
  "10 9 8 7 6 5 4 3 2 1 0 11 13 12"
  "1 1 1 1 1 2 2 2 2 3 3 3 3 4 4"
  "9 8 7 6 5 4 3 2 1 0 10 11 12 13 14 15"
  "8 6 4 3 1 0 9 7 5 2 10 11 12 13 14 15 16"
  "1 3 5 7 9 8 6 4 2 10 12 11 13 14 15 16 17 18"
  "0 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2"
  "10 9 8 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 8 9"
)

i=1
for input in "${test_cases[@]}"; do
  echo "--- Test $i: ./PmergeMe $input"
  ./PmergeMe "$input"
  echo ""
  ((i++))
done

#5. RN-1 instead RN-2
#9. RN-2 instead RN-3
#10 RN-2 instead RN-3
#11 RN-2 instead RN-3
#11 - 20 rest is still 3