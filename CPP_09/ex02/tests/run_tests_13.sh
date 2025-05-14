#!/bin/bash

#RN-3
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 13 | 1 2 3 4 5 6 7 8 9 10 11 12 13 | 1 2 3 4 5 6 7 8 9 10 11 12 13"
  "Sorted Descending 13 | 13 12 11 10 9 8 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7 8 9 10 11 12 13"
  "All Equal 13 | 7 7 7 7 7 7 7 7 7 7 7 7 7 | 7 7 7 7 7 7 7 7 7 7 7 7 7"
  "One Min 13 | 1 7 7 7 7 7 7 7 7 7 7 7 7 | 1 7 7 7 7 7 7 7 7 7 7 7 7"
  "One Max 13 | 7 1 1 1 1 1 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 1 1 1 1 1 7"
  "Random Duplicates 13 | 6 4 6 3 7 2 5 1 5 2 9 8 3 | 1 2 2 3 3 4 5 5 6 6 7 8 9"
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