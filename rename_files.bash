#!/bin/env bash
# USAGE: Search and change (hardcoded) extension of all files in a directory.

# This cmd selects all non-dir files by extension:
# grep -l -d skip "" *.sv
# Before I realized this is the wrong tool for the job.

# Loop through all files in PWD
for file in *
# For each
do
	## Seperate filename and extension. ##
	# Parameter expand the file object with safety brackets
	# and select ones with REGEX extensions.
	if [[ $file == *.sv* ]]; then
		# Parameter Expansion-Remove longest from start-REGEX
		extension="${file##*.}"
		# Parameter Expansion-Remove shortest from end-REGEX
		filename="${file%.*}"
		#echo "$file" " -> " "${filename}.v"
		# mv-Parameter-Parameter Expansion-Append new extension
		mv "$file" "${filename}.v"
	else
		echo "skipping " "$file"
	fi
done
