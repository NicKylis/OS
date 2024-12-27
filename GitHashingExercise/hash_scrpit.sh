#!/bin/bash

# Takes an argument from the user in the execution of the script and checks if it has 4 digits (true -> 0, false -> 1)
is_four_digit_int() {
    [[ $1 =~ ^[0-9]{4}$ ]]
}

# Checks the input to catch any weird ones
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 \"4-digit-integer\""
    exit 1
fi

input="$1"

if ! is_four_digit_int "$input"; then
    echo "Error: Input must be a 4-digit integer."
    exit 1
fi

# Compute SHA-256 hash
hash=$(echo -n "$input" | sha256sum | awk '{print $1}')

echo "$hash"
