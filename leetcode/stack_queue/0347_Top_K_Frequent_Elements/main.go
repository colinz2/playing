//package _347_Top_K_Frequent_Elements
package main

import (
	"fmt"
)

func topKFrequent(nums []int, k int) []int {
	freq := make(map[int]int)
	bucket := make([][]int, len(nums)+1)
	res := make([]int, 0)

	for _, n := range nums {
		freq[n]++
	}

	for k, v := range freq {
		bucket[v] = append(bucket[v], k)
	}

	for i := len(nums); i >= 0; i-- {
		for _, v := range bucket[i] {
			res = append(res, v)
			if len(res) == k {
				return res
			}
		}
	}
	return res
}

func main() {
	s1 := []int{1, 1, 1, 2, 2, 3}

	fmt.Println(topKFrequent(s1, 2))
}
