// Author: Shivshankar Pirgonde
// Adapted from online resources (Google, ChatGPT) and rewritten for learning.

package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(s string) {
	zeros, ones := 0, 0

	for _, char := range s {
		if char == '0' {
			zeros++
		} else {
			ones++
		}
	}

	if zeros != ones {
		if zeros < ones {
			fmt.Println(zeros)
		} else {
			fmt.Println(ones)
		}
	} else {
		fmt.Println(zeros - 1)
	}

}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(reader, &t)

	for i := 0; i < t; i++ {
		var s string
		fmt.Fscan(reader, &s)

		solve(s)
	}

}
