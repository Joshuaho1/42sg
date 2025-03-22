#!/bin/zsh
find . -type f -name "*.sh" -exec basename {} .sh \;
#ls -R list files in the current directory and subdirectory recursively
# | takes the output of previous command and inputs it into next command
# grep \.sh$ filters the files to only show those that end with .sh
# grep searches for patterns in input, adding the pattern as a regex allows filtering for the .sh
# sed with s is a command that performs substitution.
# The backslash is used to escape the dot from the .sh pattern
#  $ anchors the pattern to the end of the line
# // is the empty replacement part
