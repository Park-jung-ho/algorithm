using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
int N = input[0];
int K = input[1];
int[,] map = new int[N, N];
int res = 0;
int[] dx = new int[4] { -1, 1, 0, 0 };
int[] dy = new int[4] { 0, 0, -1, 1 };
for (int i = 0; i < N; i++)
{
    input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    for (int j = 0; j < N; j++)
    {
        map[i, j] = input[j];
    }
}
input = Console.ReadLine().Split().Select(int.Parse).ToArray();
int S = input[0];
int X = input[1] - 1;
int Y = input[2] - 1;
List<Queue<Tuple<int,int>>> queue = new List<Queue<Tuple<int,int>>>();
for (int i = 0; i <= K; i++)
{
    queue.Add(new Queue<Tuple<int,int>>());
}
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        if (map[i, j] != 0)
        {
            queue[map[i, j]].Enqueue(new Tuple<int,int>(i, j));
        }
    }
}

while (S > 0)
{
    S--;
    for (int i = 1; i <= K; i++)
    {
        int cnt = queue[i].Count;
        while (cnt > 0)
        {
            cnt--;
            int x, y;
            (x, y) = queue[i].Dequeue();
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (map[nx, ny] != 0) continue;
                map[nx, ny] = i;
                queue[i].Enqueue(new Tuple<int,int>(nx, ny));
                // PrintMap();
            }
        }
    }
}
// PrintMap();
res = map[X, Y];
Console.WriteLine(res);

void PrintMap()
{
    StringBuilder sb = new StringBuilder();
    sb.AppendLine($"----------------------------------");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sb.Append(map[i, j] + " ");
        }
        sb.AppendLine();
    }
    Console.WriteLine(sb);
}