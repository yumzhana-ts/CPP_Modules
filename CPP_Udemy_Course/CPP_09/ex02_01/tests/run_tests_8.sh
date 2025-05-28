#!/bin/bash

#RN-2
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 8 | 1 2 3 4 5 6 7 8 | 1 2 3 4 5 6 7 8"
  "Sorted Descending 8 | 8 7 6 5 4 3 2 1 | 1 2 3 4 5 6 7 8"
  "All Equal 8 | 3 3 3 3 3 3 3 3 | 3 3 3 3 3 3 3 3"
  "One Min 8 | 1 6 6 6 6 6 6 6 | 1 6 6 6 6 6 6 6"
  "One Max 8 | 6 1 1 1 1 1 1 1 | 1 1 1 1 1 1 1 6"
  "Random Duplicates 8 | 4 7 4 2 3 7 1 5 | 1 2 3 4 4 5 7 7"
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