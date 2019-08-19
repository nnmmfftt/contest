func isValid(s string)bool{
    var valid []rune
    for _,i:= range []rune(s){
        if i == '('{
            valid = append(valid,'(')
        }else{
            if len(valid) == 0 {
                return false
            }else   if valid[len(valid)-1] == '('{
                valid = valid[:len(valid)-1]
            }
        }
    }
    return len(valid) == 0
}
func longestValidParentheses(s string) int {
    // brute version
    // check every substring isvalid.
    // time: O(n^2), space o(n) (check substring isvalid takes O(n))
    maxLen := 0
    for i:=0; i < len(s);i++{
        for j := i+2; j <= len(s);j+=2{
            flag := isValid(s[i:j])
            fmt.Printf("%v\n",flag )
            if  flag{
                fmt.Printf("%d,%d\n",i,j)
                maxLen = int(math.Max(float64(j-i),float64(maxLen)))
            }
        }
    }
    return maxLen
}


func longestValidParentheses(s string) int {
    // dynamic version:
    // dp records every possibilities
    // notes:
    // check max substring length to current position 
    // ----------------------------------------------
    // only check the string ended by ")", the "("
    // position is dp[i] = 0. 
    // 1. 
    // dp[i-1] = '('
    // "()" is a valid condition
    // dp[i] = dp[i-2] + 2
    // 2.
    // dp[i-1] = ')'
    // "))" paired "(("
    // dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
    //
    dp := make([]int, len(s))
    maxRet := 0
    for i:= 1;i<len(s);i++{
        if s[i] == ')'{
            if s[i-1] == '('{
                dp[i] = func(i int)int{
                    if i >=2{
                        return dp[i-2]
                    }else{
                        return 0
                    }
                }(i)+2
            }else if i-dp[i-1] >0 && s[i-dp[i-1]-1] == '('{
                dp[i] = func(i int)int{
                    if i-dp[i-1] >=2{
                        return dp[i-1] + dp[i-dp[i-1]-2]
                    }else{
                        return dp[i-1]
                    }
                }(i)+2
            }
            maxRet = int(math.Max(float64(maxRet),float64(dp[i])))
        }
    }
    return maxRet
}

class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [0]
        longest = 0
        
        for c in s:
            if c == "(":
                stack.append(0)
            else:
                if len(stack) > 1:
                    val = stack.pop()
                    stack[-1] += val + 2
                    longest = max(longest, stack[-1])
                else:
                    stack = [0]
        return longest
// also we can modify method 1
// traverse all elements & check validation
func max(a, b int)int{
    if a > b{
        return a
    }else{
        return b
    }
}
func longestValidParentheses(s string) int {
    stack := make([]int)
    longest := 0
    for _, c:= range []rune(s){
        if c == '('{
            stack = append(stack, 0)
        }else{
            if len(stack) >1{
                val = stack[len(stack)-1]
                stack[len(stack)-1] +=2
                longest = max(longest,stack[len(stack)-1])
            }else{
                stack = {0}
            }
        }
    }
}