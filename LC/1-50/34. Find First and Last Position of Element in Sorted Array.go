func searchRange(nums []int, target int) []int {
    var ret []int
    for pos,i := range nums{
        if i == target{
            ret = append(ret,pos)
        }
    }
    if len(ret) == 0{
        return []int{-1,-1}
    }else if len(ret) == 1{
        ret =append(ret,ret[0])
    }
    return []int{ret[0],ret[len(ret)-1]}
}