
/*
 * 实现一个ip过滤器，对访问的ip进行限制
 * ip有三种格式：
 * 1.全ip  ：    192.168.1.1
 * 2.前面带*：   *.173.0.1
 * 3.后面带*：   192.168.*
 * 带*表示可以匹配任意IP，*可以带表多个IP段，且只能出现在开头或者结尾
 * 输出1 表示会被过滤器过滤
 * 输出0 表示不会被过滤器过滤
 * AC
 */ 
package main

import (
   "fmt"
   "regexp"
)

func helper(regSet []*regexp.Regexp, str string)bool{

   for _,j := range regSet{
      val := j.FindAll([]byte(str),-1)
      if len(val) != 0{
         return true
      }
   }
   return false
}
func main() {
   var rules, address int
   _,_ = fmt.Scanf("%d %d",&rules, &address)
   var (
      ruleSet []string
      addrSet []string
   )

   for i := 0; i < rules; i++{
      var tmp string
      _,_ = fmt.Scanf("%s", &tmp)
      if tmp[0] == '*'{
         tmp = "." + tmp
      }

      ruleSet = append(ruleSet, tmp)
   }
   for i := 0; i < address; i++{
      var tmp string
      _,_ = fmt.Scanf("%s", &tmp)
      addrSet = append(addrSet, tmp)
   }

   var regSet []*regexp.Regexp
   for i:=0; i< rules; i++{
      regSet = append(regSet, regexp.MustCompile(ruleSet[i]))
   }
   for i:=0; i< address; i++{
      if helper(regSet, addrSet[i]) == true{
         fmt.Println("1 ")
      }else{
         fmt.Println("0 ")
      }

   }

}