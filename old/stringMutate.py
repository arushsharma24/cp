from typing import List

def maximumNumber(num: str, change: List[int]):
    num = [char for char in num]
    state = 0 # 0:unstarted, 1:in progress, 2: ended
    for i in range(len(num)):
        if change[int(num[i])]>int(num[i]):
            if state == 0:
                state = 1
            if state == 1:
                num[i] = str(change[int(num[i])])   # ? 
        elif change[int(num[i])]<int(num[i]):
            if state == 1:
                state = 2
    return "".join(num)

change = [9,8,5,0,3,6,4,2,6,8]
print(maximumNumber("132", change))