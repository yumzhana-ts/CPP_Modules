#!/bin/bash

#RN-3
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 16 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16"
  "Sorted Descending 16 | 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16"
  "All Equal 16 | 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 | 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9"
  "One Min 16 | 1 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 | 1 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7"
  "One Max 16 | 7 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 7"
  "Random Duplicates 16 | 6 4 3 7 5 2 8 6 1 5 3 2 9 8 4 7 | 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9"

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