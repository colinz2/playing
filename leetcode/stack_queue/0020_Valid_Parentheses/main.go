package main

import "fmt"

func isValid(s string) bool {
	m := map[rune]int{'(':1, ')':-1, '[':2, ']':-2, '{':3, '}':-3}
	stack :=  make([]int, 0, 128)

	for _, c := range s {
		if v, e := m[c]; e {
			if v > 0 {
				stack = append(stack, v)
			} else if v < 0 {
				if len(stack) == 0 {
					return false
				}
				if stack[len(stack) - 1] != -v {
					return false
				}
				stack = stack[:len(stack) - 1]
			}
		}
	}
	
	if len(stack) > 0 {
		return false
	}
	return true
}

func main()  {
	
	fmt.Println(isValid("()[]{}"))
	fmt.Println(isValid("([[[]]]{})"))
}