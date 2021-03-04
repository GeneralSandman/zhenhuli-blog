package main

import (
	"fmt"
	_ "net/http/pprof"
	"sync"
	"time"

	"golang.org/x/time/rate"

)

func main()  {
	generateJobCallback := func(number int, wg *sync.WaitGroup, limiter *rate.Limiter) {
		defer func() {
			wg.Done()
		}()
		for {
			limiterResult := limiter.ReserveN(time.Now(), 1)
			if !limiterResult.OK() {
				fmt.Printf("[Error]limiter.event happen\n")
			}
			time.Sleep(limiterResult.Delay())
			fmt.Printf("[Info][%d][%v]\n", number, time.Now())
		}
	}

	var wg sync.WaitGroup

	startTime := time.Now()
	endTime := startTime

	limit := rate.Every(time.Duration(1000) * time.Millisecond)
	limiter := rate.NewLimiter(limit, 1)

	for i:=0;i<300;i+=1 {
		wg.Add(1)
		go generateJobCallback(i, &wg, limiter)
	}

	wg.Wait()
	endTime = time.Now()
	fmt.Printf("[info]usetime %v\n", endTime.Sub(startTime))
	return
}

