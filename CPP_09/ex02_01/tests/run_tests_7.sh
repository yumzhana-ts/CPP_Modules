#!/bin/bash

#RN-2
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 7 | 1 2 3 4 5 6 7 | 1 2 3 4 5 6 7"
  "Sorted Descending 7 | 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7"
  "All Equal 7 | 9 9 9 9 9 9 9 | 9 9 9 9 9 9 9"
  "One Min 7 | 1 9 9 9 9 9 9 | 1 9 9 9 9 9 9"
  "One Max 7 | 9 1 1 1 1 1 1 | 1 1 1 1 1 1 9"
  "Random Duplicates 7 | 5 2 5 3 1 2 4 | 1 2 2 3 4 5 5"
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