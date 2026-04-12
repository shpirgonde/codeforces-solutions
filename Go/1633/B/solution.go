// Author: Shivshankar Pirgonde

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(w *bufio.Writer, s []byte) {
	zeros, ones := 0, 0

	for _, b := range s {
		if b == '0' {
			zeros++
		} else {
			ones++
		}
	}

	ans := zeros

	if ones < zeros {
		ans = ones
	}
	if zeros == ones {
		ans--
	}

	fmt.Fprintln(w, ans)

}

func main() {

	const maxCap = 200005

	sc := bufio.NewScanner(os.Stdin)

	buf := make([]byte, maxCap)
	sc.Buffer(buf, maxCap)

	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	//Read test input using	strconv method
	if !sc.Scan() {
		return
	}

	t, _ := strconv.Atoi(sc.Text())

	for i := 0; i < t; i++ {
		if !sc.Scan() {
			break
		}

		solve(out, sc.Bytes())
	}
}
