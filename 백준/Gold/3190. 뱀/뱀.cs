using System;
using System.Text;
using static System.Console;

namespace Algorithm
{
    using System;
    using System.Collections.Generic;

    public class IMPL_5
    {
        // https://www.acmicpc.net/problem/3190
        // 조건 1. 매 초 이동
        // 조건 2. 벽과 몸에 부딪히면 게임종료
        // 조건 3. 이동한 칸에 사과가 있으면 사과가 없어지고 꼬리는 움직이지않음 (몸이 한칸 길어진다)
        // 조건 4. 이동 시 꼬리가 위치한 칸을 비워준다 (한칸 이동)

        static int n; // 보드의 크기 [2 <= n <= 100]
        static int k; // 사과의 개수 [0 <= k <= 100]
        static int[,] board; // 사과와 뱀의 위치를 기록할 보드
        static int l; // 뱀의 방향변환 횟수 [1 <= L <= 100]
        static int x; // 게임시작시간으로부터 x 초 후 [x <= 1만]
        static string c; // 방향 [L(왼쪽) or D(오른쪽)]
        static LinkedList<Tuple<int, int>> snake = new LinkedList<Tuple<int, int>>(); // 뱀 좌표 저장
                                                                                      // dx dy  {오른쪽 아래 왼쪽 위}
        static int[] dx = { 0, 1, 0, -1 };
        static int[] dy = { 1, 0, -1, 0 };
        static int moveIdx = 0; // dx dy의 인덱스, 방향전환시 -1 or +1
        static int time = 0; // 게임시간(출력할 정답)
        static bool isGameOver = false;

        public static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
            // Console.WriteLine($"n = {n}");
            board = new int[n, n];
            board[0, 0] = 2; // 2는 뱀의 위치
            snake.AddFirst(new Tuple<int, int>(0, 0));
            k = int.Parse(Console.ReadLine());
            // Console.WriteLine($"k = {k}");
            for (int i = 0; i < k; i++)
            {
                int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
                // Console.WriteLine($"input{i+1} = {input[0]} {input[1]}");
                int row = input[0] - 1;
                int col = input[1] - 1;
                board[row, col] = 1; // 1은 사과의 위치
            }

            l = int.Parse(Console.ReadLine());
            // Console.WriteLine($"l = {l}");
            for (int i = 0; i < l; i++)
            {
                string[] input = Console.ReadLine().Split();
                // Console.WriteLine($"input{i+1} = {input[0]} {input[1]}");
                x = int.Parse(input[0]);
                c = input[1];

                if (isGameOver || !Move()) isGameOver = true;
            }
            if (!isGameOver)
            {
                x = int.MaxValue;
                Move();
            }

            Console.WriteLine(time);
        }
        public static bool Move()
        {
            while (true)
            {
                if (time == x) break;

                time++; // 시간 증가

                // snake의 머리와 방향으로 한칸 이동
                int nx = snake.First().Item1 + dx[moveIdx];
                int ny = snake.First().Item2 + dy[moveIdx];
                // Console.WriteLine($"idx = {moveIdx} ({nx},{ny})");
                // 다음 위치 (nx,ny)를 기준으로 게임오버 체크
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                {
                    // 벽에 충돌
                    return false;
                }
                if (board[nx, ny] == 2)
                {
                    // 자신과 충돌
                    return false;
                }
                // 이동할 위치에 사과가 있는지 체크 후 이동
                if (board[nx, ny] == 0)
                {
                    // 사과가 없다 -> 꼬리 삭제
                    board[snake.Last.Value.Item1, snake.Last.Value.Item2] = 0;
                    snake.RemoveLast();
                }
                // 머리 추가
                board[nx, ny] = 2;
                snake.AddFirst(new Tuple<int, int>(nx, ny));

                // PrintMap();
            }

            if (c == "L")
            {
                // 왼쪽회전
                moveIdx = moveIdx - 1 < 0 ? 3 : moveIdx - 1;
            }
            else
            {
                // 오른쪽회전
                moveIdx = moveIdx + 1 > 3 ? 0 : moveIdx + 1;
            }
            return true;
        }
        void PrintMap()
        {
            Console.WriteLine($"----TIME : {time} sec----");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(board[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
