package main
// 判断输出的IP是否为合法的IP
// IP可以为IPv6或IPv4
import (
	"fmt"
	"net"
	"strings"
)
func parse6(addr net.IP)bool{
	for i := 0; i < 10; i++ {
		// Go中ipv4的头部分为空，为与IPv6长度相同
		if addr[i] == 0 {
			continue
		}else {
			return false
		}
	}
	return true
}
func main(){
	var s string
	_,_ = fmt.Scanf("%s", &s)
	vec := strings.Split(s,"\\.")
	// 题中此情况未说明，最后才发现
	addr := net.ParseIP(s)
	if len(addr) == 0 {
		fmt.Println("Neither")
	}else if parse6(addr) == true {
		fmt.Println("IPv4")
	}else if parse6(addr) == false{
		fmt.Println("IPv6")
	}else{
		fmt.Println("Neither")
	}
}

