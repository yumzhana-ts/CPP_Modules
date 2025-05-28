#!/bin/bash

#RN-3
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 10 | 1 2 3 4 5 6 7 8 9 10 | 1 2 3 4 5 6 7 8 9 10"
  "Sorted Descending 10 | 10 9 8 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7 8 9 10"
  "All Equal 10 | 7 7 7 7 7 7 7 7 7 7 | 7 7 7 7 7 7 7 7 7 7"
  "One Min 10 | 1 9 9 9 9 9 9 9 9 9 | 1 9 9 9 9 9 9 9 9 9"
  "One Max 10 | 9 1 1 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 1 1 9"
  "Pairs 10 | 2 2 4 4 6 6 8 8 10 10 | 2 2 4 4 6 6 8 8 10 10"
  "Random Mix | 5 3 9 1 6 2 8 7 10 4 | 1 2 3 4 5 6 7 8 9 10"
  "Duplicates Random | 3 5 3 7 1 5 2 9 2 6 | 1 2 2 3 3 5 5 6 7 9"
)

echo "== Running PmergeMe Tests =="

for test in "${test_cases[@]}"; do
  # Split test case into name, input, expected
  IFS='|' read -r name input expected <<< "$test"

  # Trim whitespace
  name=$(echo "$name" | xargs)
  input=$(echo "$input" | xargs)
  expected=$(echo "$expected" | xargs)

  # Run the program and capture output
  actual=$(./PmergeMe "$input" 2>/dev/null)

  # Clean and normalize output
  actual_clean=$(echo "$actual" | tr -s '[:space:]' ' ' | xargs)

  # Compare output
  if [[ "$actual_clean" == "$expected" ]]; then
    echo "✅ $name — PASSED"
  else
    echo "❌ $name — FAILED"
    echo "   Input:    $input"
    echo "   Expected: $expected"
    echo "   Got:      $actual_clean"
  fi
done