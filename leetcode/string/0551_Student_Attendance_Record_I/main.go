package main

import "fmt"

func checkRecord(s string) bool {
    l, a := 0, 0
    for i := 0; i < len(s); i++ {
        if (s[i] == 'L') {
            l += 1
        } else if (s[i] == 'A') {
            l = 0;
            a += 1
        } else {
            l = 0;
        }
        
        if l > 2 || a > 1 {
            return false
        }
    }
    return true
}

func main() {
    fmt.Println(checkRecord("PPALLP"))
}
