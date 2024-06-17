#!/bin/bash
# run ./generateData 0 {n} 0 for n {64, 128, ... 1048576}

# Array of sizes
sizes=(64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576)

# Loop over sizes
for size in "${sizes[@]}"; do
	./generateData 2 $size 0
done