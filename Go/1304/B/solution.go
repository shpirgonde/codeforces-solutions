// Author: Shivshankar Pirgonde

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	//Fast I/O setup

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	if !scanner.Scan() {
		return
	}

	//Read n and m
	var n, m int
	fmt.Sscanf(scanner.Text(), "%d", &n)
	if !scanner.Scan() {
		return
	}
	fmt.Sscanf(scanner.Text(), "%d", &m)

	//Pre-allocate the slice capacity to avoid resizing
	inputStrings := make([]string, 0, n)
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			inputStrings = append(inputStrings, scanner.Text())
		}
	}

	solve(n, m, inputStrings)
}

//Function to solve the problem

func solve(n, m int, inputStrings []string) {
	counts := make(map[string]int)
	for _, s := range inputStrings {
		counts[s]++
	}

	var leftPart []string
	var middlePart string

	//1.Iterate through the original list to maintain a consistent order

	for _, s := range inputStrings {
		rev := reverse(s)

		if s == rev {
			//case 1: self palindromes like 'aba'
			//If we have at least 2 they can be pair, one on left other on right
			if counts[s] >= 2 {
				leftPart = append(leftPart, s)
				counts[s] = counts[s] - 2
			}

			//If 1 remains, it can be single middle piece
			if middlePart == "" && counts[s] == 1 {
				middlePart = s
				counts[s]--
			}
		} else {
			//case 2: Reverse Pairs like 'abc' and 'cba'
			if counts[s] > 0 && counts[rev] > 0 {
				leftPart = append(leftPart, s)
				counts[s]--
				counts[rev]--
			}

		}
	}

	//2.Assebmle the final string

	//Exact Preallocation
	totalLen := (len(leftPart) * 2 * m)
	if middlePart != "" {
		totalLen = totalLen + m
	}

	var builder strings.Builder

	//Grow reserves exactly the bytes we need in one go
	builder.Grow(totalLen)

	//3.Asseble complete string
	for _, s := range leftPart {
		builder.WriteString(s)
	}

	builder.WriteString(middlePart)

	for i := len(leftPart) - 1; i >= 0; i-- {
		builder.WriteString(reverse(leftPart[i]))
	}

	//4.Output
	result := builder.String()

	fmt.Println(len(result))
	fmt.Println(result)

}

// Helper func to reverse a string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
