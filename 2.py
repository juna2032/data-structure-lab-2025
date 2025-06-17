# 프로젝트 문제 2번
input = ")))()"

def problem2(input):
    
    result = 0         # 추가해야 할 괄호 수
    balance = 0        # 열린 괄호의 수를 저장할 변수

    for char in input:
        if char == '(':
            balance += 1    # 여는 괄호면 balance +1
        else:  # char == ')'
            if balance > 0:
                balance -= 1  # 짝이 맞는 여는 괄호가 있다면 닫아줌
            else:
                result += 1   # 짝이 없으므로 여는 괄호 하나 추가해야 함

    result += balance  # 남은 여는 괄호는 닫아야 하므로 result에 더함

    return result

result = problem2(input)

assert result == 3
print("정답입니다.")