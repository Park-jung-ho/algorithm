def solution(t, p):
    answer = 0
    for i in range(len(t)-len(p)+1):
        a = t[i:i+len(p)]
        if a <= p:
            answer += 1
    
    return answer