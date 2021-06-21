package main

import (
	"fmt"
	"time"
)

func main() {
	var a int64
	var b int64
	var t int64
	a = 1624204800
	b = 1624291200

	for t = a; t<b;t+=60 {
		currentTimestamp := t
		endTimestamp := currentTimestamp - currentTimestamp%3600
		startTimestamp := endTimestamp - 3600

		if currentTimestamp - endTimestamp < 45 * 60 {
			continue
		}


		fmt.Printf("%s\t%s\t%s\n", 
		time.Unix(t, 0).Format("2006-01-02 15:04:05"),
		time.Unix(startTimestamp, 0).Format("2006-01-02 15:04:05"),
		time.Unix(endTimestamp, 0).Format("2006-01-02 15:04:05"))
	}
}
