package main

import (
	"fmt"
	"strconv"
	"unicode"
)
func cal(post string)int{
	var stack []interface{}
	fixLen := len(post)
	for i := 0; i < fixLen; i++ {
		nextChar := string(post[i])
		if unicode.IsDigit(rune(post[i])) {
			stack = append(stack, nextChar)
		} else {
			switch nextChar {
			case "|":
				num1, _ := strconv.Atoi(stack[len(stack)-1].(string))
				stack = stack[:len(stack)-1]
				num2, _ := strconv.Atoi(stack[len(stack)-1].(string))
				stack = stack[:len(stack)-1]
				stack = append(stack, strconv.Itoa(num1|num2))
			case "&":
				num1, _ := strconv.Atoi(stack[len(stack)-1].(string))
				stack = stack[:len(stack)-1]
				num2, _ := strconv.Atoi(stack[len(stack)-1].(string))
				stack = stack[:len(stack)-1]
				stack = append(stack, strconv.Itoa(num1&num2))
			case "!":
				num1, _ := strconv.Atoi(stack[len(stack)-1].(string))
				stack = stack[:len(stack)-1]
				if num1 == 0 {
					stack = append(stack, strconv.Itoa(1))
				} else {
					stack = append(stack, strconv.Itoa(0))
				}
			}
		}
	}
	result, _ := strconv.Atoi(stack[len(stack)-1].(string))

	return result

}

func intopos(e string) string{
	var stack []interface{}
	post := ""
	expL := len(e)
	for i := 0; i < expL; i++ {
		char := string(e[i])
		switch char {
		case " ":
			continue
		case "(":
			stack = append(stack, "(")
		case ")":
			for len(stack) != 0 {
				preChar := stack[len(stack)-1]
				if preChar == "(" {
					stack = stack[:len(stack)-1]
					break
				}

				post += preChar.(string)
				stack = stack[:len(stack)-1]
			}
		case "0", "1", "2", "3", "4", "5", "6", "7", "8", "9:":
			j := i
			digit := ""
			for ; j < expL && unicode.IsDigit(rune(e[j])); j++ {
				digit += string(e[j])
			}
			post += digit
			i = j - 1
		default:
			for len(stack) != 0 {
				top := stack[len(stack)-1]
				if top == "(" || isLower(top.(string), char) {
					break
				}
				post += top.(string)
				stack = stack[:len(stack)-1]
			}
			stack = append(stack,char)
		}
	}
	for len(stack) != 0 {
		post += stack[len(stack)-1].(string)
		stack = stack[:len(stack)-1]
	}
	return post
}
func isLower(top , newT string) bool {
	switch top {
	case "|":
		if newT == "&" || newT == "!" {
			return true
		}
	case "&":
		if newT == "!" {
			return true
		}
	case "(":
		return true
	}
	return false
}

func main(){
	var st string
	_, _ = fmt.Scanf("%s", &st)
	pos := intopos(st)
	fmt.Println(intopos(st))
	fmt.Println(cal(pos))
}
