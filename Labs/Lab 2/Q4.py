def binary_search_deluxe(arr, target):
    first_index = find_first_index(arr, target)
    last_index = find_last_index(arr, target)
    return [first_index, last_index]

def find_first_index(arr, target):
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] < target:
            start = mid + 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            if mid == 0 or arr[mid - 1] != target:
                return mid
            else:
                end = mid - 1
    return -1

def find_last_index(arr, target):
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] < target:
            start = mid + 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            if mid == len(arr) - 1 or arr[mid + 1] != target:
                return mid
            else:
                start = mid + 1
    return -1
print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 10))