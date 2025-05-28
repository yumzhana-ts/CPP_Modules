#!/bin/bash

#RN-1
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending | 1 2 3 4  | 1 2 3 4"
  "Sorted Descending | 4 3 2 1 | 1 2 3 4"
  "All Equal | 5 5 5 5 | 5 5 5 5"
  "One Min | 1 5 5 5 | 1 5 5 5"
  "One Max | 5 1 1 1 | 1 1 1 5"
  "Two Pairs | 3 3 7 7 | 3 3 7 7"
  "Random Duplicates | 2 4 2 3 | 2 2 3 4"
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