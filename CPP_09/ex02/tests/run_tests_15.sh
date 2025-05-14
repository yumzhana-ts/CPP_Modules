#!/bin/bash

#RN-3
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 15 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"
  "Sorted Descending 15 | 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"
  "All Equal 15 | 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 | 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8"
  "One Min 15 | 1 8 8 8 8 8 8 8 8 8 8 8 8 8 8 | 1 8 8 8 8 8 8 8 8 8 8 8 8 8 8"
  "One Max 15 | 8 1 1 1 1 1 1 1 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 1 1 1 1 1 1 1 8"
  "Random Duplicates 15 | 5 2 7 1 6 2 9 4 6 3 5 8 3 7 4 | 1 2 2 3 3 4 4 5 5 6 6 7 7 8 9"

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