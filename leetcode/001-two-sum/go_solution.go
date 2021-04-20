package main

func twoSum(nums []int, target int) []int {
	var result []int
    if len(nums) < 2 {
		return result
	}

	hashTable := make(map[int]int)
	for i:=0;i<len(nums);i+=1{
		hashTable[nums[i]] = i
	}

	for i:=0;i<len(nums);i+=1{
		if v,ok:=hashTable[target-nums[i]]; ok && v != i {
			result = append(result, i)
			result = append(result, v)
			break;
		}
	}


	return result
}

func main() {
	
}
