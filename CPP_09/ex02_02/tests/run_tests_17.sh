#!/bin/bash

#RN-4
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 17 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17"
  "Sorted Descending 17 | 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17"
  "All Equal 17 | 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 | 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4"
  "One Min 17 | 1 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 | 1 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6"
  "One Max 17 | 6 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 6"
  "Random Duplicates 17 | 5 2 1 3 2 6 5 4 3 7 6 8 4 9 7 8 9 | 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9"

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