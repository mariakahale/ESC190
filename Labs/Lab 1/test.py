arr1 = [5,6,7,8,6,7]
arr2 = [6,7]

for i in range(0,len(arr1)):
    j = 0
    if arr1[i+j] == arr2[j]:
        while (arr1[i+j] == arr2[j]) and (j < len(arr2)-1) and ((i+j) < len(arr1)):
            j+=1
            print("akjsf", i+j, j, arr1[i+j], arr2[j])
        if j == len(arr2)-1:
            for k in range(len(arr2)):
                arr1[i+k] = 0

print(arr1,arr2)