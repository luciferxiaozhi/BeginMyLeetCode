# pseudocode
# recursion version
def all_subsets(given_array):
    subset = new int [given_array.length]
    helper(given_array, subset, 0)

def helper(given_array, subset, i):
    if i == given_array.length:
        print_set(subset)
    else:
        subset[i] = NULL
        helper(given_array, subset, i+1)
        subset[i] = given_array[i]
        helper(given_array, subset, i+1)

# iterative version
def all_subsets(given_array):
    res = []
    res.append([])
    for num in given_array:
        for each_res in res:
            if num in each_res:
                continue
            new_list = list(each_res)
            new_list.append(num)
            res.append(new_list)

    return res

        
