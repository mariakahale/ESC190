
def min_c(denom, target):
	dp = [1e6]*(target+1)

	dp[0] = 0

	for i in range(0,len(denom)):
		for j in range(denom[i], target+1):
				dp[j] = min(dp[j],dp[j-denom[i]]+1)


	return dp

def return_comb(denom, target):
	OPT = min_c(denom, target)
	num_coins = OPT[target]
	denom.sort()
	i = len(denom)-1
	j=1
	comb = []

	while i>=0:
		if denom[i]>target:
			i-=1
		while (((denom[i])*j < target )and (j <=(OPT[target]-len(comb)+1))):
			comb.append(denom[i])
			j+=1
		j=0
		i-=1
		print(i)

	return comb





	# for i in range(0, len(denom)-1):
	# 	track_coins = num_coins
	# 	while tracker <0:
	# 		if (tracker - (track_coins*1):



print(min_c([1,4,5],8))
print(return_comb([1,4,5],8))
	

