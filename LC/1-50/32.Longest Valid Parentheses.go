func longestValidParentheses(s string) int {
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
            maxRet= int(math.Max(float64(maxRet),float64(dp[i])))
        }
    }
    return maxRet
}