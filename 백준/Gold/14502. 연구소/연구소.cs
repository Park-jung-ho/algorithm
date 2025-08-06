using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
int N = input[0];
int M = input[1];
int[,] map = new int[N, M];
int[] dx = new int[4] { -1, 1, 0, 0 };
int[] dy = new int[4] { 0, 0, -1, 1 };
int res = 0;
for (int i = 0; i < N; i++)
{
    input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    for (int j = 0; j < M; j++)
    {
        map[i, j] = input[j];
    }
}
MakeWall(0,0,0);
Console.WriteLine(res);

void PrintMap()
{
    StringBuilder sb = new StringBuilder();
    sb.AppendLine($"----------------------------------");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sb.Append(map[i, j] + " ");
        }
        sb.AppendLine();
    }
    Console.WriteLine(sb);
}
void MakeWall(int x, int y, int cnt)
{
    if (cnt == 3)
    {
        Check();
        return;
    }

    for (int i = x; i < N; i++)
    {
        for (int j = y; j < M; j++)
        {
            if (map[i, j] != 0) continue;
            
            map[i, j] = 1;
            MakeWall(i, j+1, cnt + 1);
            map[i, j] = 0;
        }

        y = 0;
    }
}
void Check()
{
    // PrintMap();
    Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
    Queue<Tuple<int, int>> clearQ = new Queue<Tuple<int, int>>();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i, j] == 2)
            {
                queue.Enqueue(new Tuple<int, int>(i, j));
            }
        }
    }

    int x, y;
    while (queue.Count > 0)
    {
        (x, y) = queue.Dequeue();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx, ny] == 0)
            {
                map[nx, ny] = 2;
                clearQ.Enqueue(new Tuple<int, int>(nx, ny));
                queue.Enqueue(new Tuple<int, int>(nx, ny));
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i, j] == 0) cnt++;
        }
    }
    res = Math.Max(res, cnt);
    // PrintMap();
    while (clearQ.Count > 0)
    {
        (x, y) = clearQ.Dequeue();
        map[x, y] = 0;
    }
}