# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    # 이동 방향: 상, 좌, 우, 하 (우선순위)
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    # 먹을 수 있는 꿀벌집을 BFS로 탐색하는 함수
    def bfs(x, y, size):
        from collections import deque
        visited = [[-1]*N for _ in range(N)]
        q = deque()
        q.append((x, y))
        visited[x][y] = 0
        edible = []

        while q:
            cx, cy = q.popleft()
            for d in range(4):
                nx = cx + dx[d]
                ny = cy + dy[d]
                if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1:
                    if forest[nx][ny] <= size:
                        visited[nx][ny] = visited[cx][cy] + 1
                        q.append((nx, ny))
                        if 0 < forest[nx][ny] < size:
                            edible.append((visited[nx][ny], nx, ny))
        
        # 조건: 거리 → 위쪽 → 왼쪽 우선순위로 정렬
        edible.sort()
        return edible[0] if edible else None

    while True:
        target = bfs(bear_x, bear_y, bear_size)
        if target is None:
            break  # 먹을 수 있는 벌집이 없으면 종료

        dist, nx, ny = target # 먹을 벌집 정보 받기
        time += dist          # 이동 시간 누적
        honeycomb_count += 1  # 꿀 하나 먹음
        forest[nx][ny] = 0    # 벌집 제거
        bear_x, bear_y = nx, ny  # 곰 위치 갱신

        # 곰이 자기 크기만큼 꿀을 먹으면 크기 증가
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time
    return result

result = problem3(input)

assert result == 14
print("정답입니다.")