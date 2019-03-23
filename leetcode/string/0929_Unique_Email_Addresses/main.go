package main

import "fmt"
import "strings"

func numUniqueEmails(emails []string) int {
	seen := make(map[string]bool)
	for _, email := range emails {
		comp := strings.Split(email, "@")
		if len(comp) == 2 {
			comp[0] = strings.Split(comp[0], "+")[0]
			comp[0] = strings.Replace(comp[0], ".", "", -1)
			finalEmail := strings.Join(comp, "@")
			fmt.Println(finalEmail)
			seen[finalEmail] = true
		}
	}
	return len(seen)
}

func main() {
	emails := []string{"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
		"testemail+david@lee.tcode.com"}

	ret := numUniqueEmails(emails)

	fmt.Println("ret = ", ret)

}
