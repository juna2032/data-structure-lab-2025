# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    mean = sum(input) // len(input)          # 평균: 총합 / 개수 (정수 나눗셈)
    sorted_input = sorted(input)             # 정렬해서 중앙값 구하기
    median = sorted_input[len(input) // 2]   # 5개일 때 가운데 값은 인덱스 2
    result = [mean, median]
    return result

result = problem1(input)

assert result == [34, 30]
print("정답입니다.")