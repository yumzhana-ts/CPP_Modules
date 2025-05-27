#!/bin/bash

#RN-1
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 3 | 1 2 3 | 1 2 3"
  "Sorted Descending 3 | 3 2 1 | 1 2 3"
  "All Equal 3 | 7 7 7 | 7 7 7"
  "One Min 3 | 1 9 9 | 1 9 9"
  "One Max 3 | 9 1 1 | 1 1 9"
  "Random Duplicates 3 | 2 3 2 | 2 2 3"
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