def solution(bin):

    dec=0
    for i, bit in enumerate(bin):
        dec+=(2**i)*int(bit)

    rem = ""
    while True:
        rem += str(int(dec)%6)
        print(rem)
        dec = int(dec/6)
        if dec==0:
            break
    
    return 0

print(solution([True, False]))